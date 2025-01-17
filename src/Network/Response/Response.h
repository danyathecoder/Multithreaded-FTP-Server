#pragma once

#include <map>
#include <string>
#include <sstream>
#include <initializer_list>
#include <utility>

#include <unistd.h>

#include "../Server/Server.h"
#include "../Client/Client.h"
#include "../StatusCodes.h"

using namespace std;

class FTPResponse {
private:
    FTPClient& request;
public:
    explicit FTPResponse(FTPClient& req) : request(req) {};

    void Send(StatusCodes code, string message);

    void SendBinary(string message);
};