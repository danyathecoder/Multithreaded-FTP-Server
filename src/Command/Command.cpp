#include "Command.h"
#include "../Logger/Logger.h"

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch) && ch != '\n';
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch) && ch != '\n';
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/**
 * Unpack
 * Client input parser with regular expressions usage
 * @param data inputted string
 * @return FTP command, args
 */
pair<FTPCommandList, string> FTPCommand::Unpack(string data) {
    trim(data);
    regex commandParser("([A-Za-z]+)(?: +(.+))?");
    smatch match;

    if (!regex_match(data, match, commandParser)) {
        Logger::Print(Logger::Levels::INFO, "AHAHAHAH: " + data);
        throw UndefinedCommand();
    }

    if (match.empty()) {
        throw UndefinedCommand();
    }

    string command = match.str(1);
    for_each(command.begin(), command.end(), [](char &element){ element = toupper(element); });
    
    if (FTPCommandListMap.find(command) == FTPCommandListMap.end()) {
        throw UndefinedCommand();
    }

    return { FTPCommandListMap[command], match.str(2) };
}

/**
 * Get command
 * Getting stringify command
 * @param command
 * @return optional string
 */
string FTPCommand::GetCommand(FTPCommandList command) {
    for (auto [commandStringify, reservedCommand] : FTPCommandListMap) {
        if (reservedCommand == command) {
            return commandStringify;
        }
    }
    return {};
}

