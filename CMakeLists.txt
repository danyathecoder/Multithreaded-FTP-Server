cmake_minimum_required(VERSION 3.10)

# set the project name
project(FTPServer C CXX)

# add the executable
add_executable(
    FTPServer src/main.cpp

        src/Network/Server/Server.h
        src/Network/Server/Server.cpp

        src/Network/Response/Response.cpp
        src/Network/Response/Response.h

        src/Network/Client/Client.h
        src/Network/Client/Client.cpp
    
    src/Network/StatusCodes.h

    src/Command/Command.h
    src/Command/Command.cpp

        src/Executor/Executor.h
        src/Executor/Executor.cpp

        src/Logger/Logger.h
        src/Logger/Logger.cpp

        src/Network/DataChannel/DataChannel.cpp
        src/Network/DataChannel/DataChannel.h

    src/Exception/LostConnection.h
    src/Exception/UndefinedCommand.h
    src/Exception/NotLogged.h
    src/Exception/NoDataConnection.h
    src/Exception/AlreadyDeclared.h
    src/Exception/LoggedSuccessfully.h)

set_property(TARGET FTPServer PROPERTY CXX_STANDARD 14)

# including pthread.h library
SET(THREADS_PREFER_PTHREAD_FLAG TRUE)
FIND_PACKAGE(Threads REQUIRED)
TARGET_LINK_LIBRARIES(FTPServer Threads::Threads)
TARGET_COMPILE_OPTIONS(FTPServer INTERFACE Threads::Threads)

target_link_libraries(FTPServer stdc++fs)