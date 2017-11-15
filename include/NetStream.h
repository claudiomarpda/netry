/**
 * Netry is a high level networking implementation of The Single UNIX Specification, Version 2.
 * @see: http://pubs.opengroup.org/onlinepubs/7908799/xnsix.html
 */
//
// Created by mz on 22/10/17.
//

#ifndef NETRY_NETSTREAM_H
#define NETRY_NETSTREAM_H

#include <netinet/in.h> // Internet Protocol family
#include <arpa/inet.h> // Definitions for internet operations
#include <unistd.h>
#include <string>

namespace netry {

    /**
     * Uses a Socket File Descriptor to send data to an endpoint.
     */
    class NetStream {

        const unsigned int kStringEndLength = 1;

    private:
        int fileDescriptor;

    public:

        NetStream();

        // Explicit keyword prevents the compiler from using this constructor for implicit conversions
        explicit NetStream(int fileDescriptor);

        /**
        * Close the File Descriptor
        */
        void close();

        /**
        * Write bytes to a socket endpoint
        * @param bytes
        * @param size
        */
        void writeBytes(const char *bytes, size_t n);

        ssize_t readBytes(char buffer[]);

        /**
        * Writes a string to a socket endpoint
        */
        void writeString(std::string message);

        /**
        * Receive a string from a socket stream
        * <p>
        * @return the received string
        */
        std::string readString() const;

        int getFileDescriptor() const;

        void setFileDescriptor(int fileDescriptor);

    };
}


#endif // NETRY_NETSTREAM_H
