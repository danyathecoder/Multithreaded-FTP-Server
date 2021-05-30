#pragma once

#include <map>
#include <string>
#include <regex>
#include <optional>

#include "../Constants.h"
#include "../Network/StatusCodes.h"

#include "../Exception/UndefinedCommand.h"

using namespace std;

enum class FTPCommandList {
    ABOR, /* Abort file loading */
    CWD, /* Change dir */
    EPSV, /* Enter into passive mode */
    LIST, /* List of files (through DATA connection) */
    MKD, /* Abort file loading */
    PASS, /* Abort file loading */
    PASV, /* Abort file loading */
    PWD, /* Abort file loading */
    RETR, /* Abort file loading */
    RMD, /* Abort file loading */
    STOR, /* Abort file loading */
    RNFR, /* Abort file loading */
    USER, /* Abort file loading */
    DELE, /* Delete file (DELE filename) */
    QUIT, /* Abort file loading */
    RNTO,
    NOOP
};

static map<string, FTPCommandList> FTPCommandListMap = {
    { "ABOR", FTPCommandList::ABOR },
    { "CWD", FTPCommandList::CWD },
    { "DELE", FTPCommandList::DELE },
    { "EPSV", FTPCommandList::EPSV },
    { "LIST", FTPCommandList::LIST },
    { "MKD", FTPCommandList::MKD },
    { "PASS", FTPCommandList::PASS },
    { "PASV", FTPCommandList::PASV },
    { "PWD", FTPCommandList::PWD },
    { "QUIT", FTPCommandList::QUIT },
    { "RETR", FTPCommandList::RETR },
    { "RMD", FTPCommandList::RMD },
    { "RNFR", FTPCommandList::RNFR },
    { "STOR", FTPCommandList::STOR },
    { "USER", FTPCommandList::USER },
    {"RNTO", FTPCommandList::RNTO},
    {"NOOP", FTPCommandList::NOOP }
};

static map<string, FTPCommandList> notLoggedAllowed = {
        { "USER", FTPCommandList::USER },
        { "PASS", FTPCommandList::PASS }
};

/**
 * @class 
 * FTP command
 * Packing and unpacking messages
 */
class FTPCommand {
public:
    static pair<FTPCommandList, string> Unpack(string data);
    static string GetCommand(FTPCommandList command);
};