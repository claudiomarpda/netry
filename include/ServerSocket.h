/**
 * Netry is a high level networking implementation of The Single UNIX Specification, Version 2.
 * @see: http://pubs.opengroup.org/onlinepubs/7908799/xnsix.html
 */
//
// Created by mz on 22/10/17.
//

#ifndef NETRY_SERVERSOCKET_H
#define NETRY_SERVERSOCKET_H

#include <netinet/in.h> // Internet Protocol family
#include <arpa/inet.h> // Definitions for internet operations
#include <cstring>
#include <unistd.h>
#include "SocketException.h"

namespace netry {

    /**
     * Allows to wait for clients connections with networking sockets.
     * Config: IPv4 internet address and TCP protocol.
     */
    class ServerSocket {

    private:
        int serverSocketFd; // File Descriptor
        struct sockaddr_in serverAddress; // Describes an internet socket address
        socklen_t addressSize;
        int port; // Where it will be listening

    public:

        ServerSocket();

        // Explicit keyword prevents the compiler from using this constructor for implicit conversions
        explicit ServerSocket(int port) throw(SocketException);

        void bind(int port) throw(SocketException);

        int accept() throw(SocketException);

        void close();

    };
}

#endif // NETRY_SERVERSOCKET_H