/**
 * Netry is a high level networking implementation of The Single UNIX Specification, Version 2.
 * @see: http://pubs.opengroup.org/onlinepubs/7908799/xnsix.html
 */
//
// Created by mz on 22/10/17.
//

#include "../include/NetStream.h"

netry::NetStream::NetStream() = default;

/**
 * Constructor that initiates the File Descriptor
 */
netry::NetStream::NetStream(int fileDescriptor) : fileDescriptor(fileDescriptor) {}

/**
 * Close the File Descriptor
 */
void netry::NetStream::close() {
    ::close(fileDescriptor);
}

/**
 * Write bytes to a socket endpoint
 * @param bytes
 * @param size
 */
void netry::NetStream::writeBytes(const char *bytes, size_t size) {

    // TODO: check if connection is valid before transaction and throw an exception otherwise

    // Sends the number of bytes that will be sent
    send(fileDescriptor, &size, sizeof(size_t), 0);
    // Sends the bytes from buffer
    send(fileDescriptor, bytes, size, 0);
}

/**
 * Receive bytes trough socket
 *
 * @param buffer:
 * @return the number of bytes read
 */
ssize_t netry::NetStream::readBytes(char buffer[]) {

    // TODO: check if connection is valid before transaction and throw an exception otherwise

    size_t bytesReceived = 0;
    // Receives the number of bytes that will come from the buffer
    recv(fileDescriptor, &bytesReceived, sizeof(size_t), 0);
    // Receives the data from buffer according to the number of bytes
    return recv(fileDescriptor, buffer, bytesReceived, 0);
}

/**
 * Writes a string to a socket endpoint
 */
void netry::NetStream::writeString(std::string message) {

    // TODO: check if connection is valid before transaction and throw an exception otherwise

    // Converts string to const char *
    const char *c = message.c_str();
    // Gets the size of the string
    const size_t size = message.length() + kStringEndLength;
    // Sends the number of bytes of the string
    send(fileDescriptor, &size, sizeof(size_t), 0);
    // Sends the string
    send(fileDescriptor, c, size, 0);
}

/**
 * Receive a string from a socket stream
 *
 * @return the received string
 */
std::string netry::NetStream::readString() const {

    // TODO: check if connection is valid before transaction and throw an exception otherwise

    size_t bytesReceived = 0;
    // Receives the number of bytes of the string
    recv(fileDescriptor, &bytesReceived, sizeof(size_t), 0);
    char buffer[bytesReceived];
    // Receives the string
    recv(fileDescriptor, buffer, bytesReceived, 0);
    return std::string(buffer, bytesReceived - 1);
}

int netry::NetStream::getFileDescriptor() const {
    return fileDescriptor;
}

void netry::NetStream::setFileDescriptor(int fileDescriptor) {
    NetStream::fileDescriptor = fileDescriptor;
}

