cmake_minimum_required(VERSION 3.9)
project(netry)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES include/NetStream.h src/NetStream.cpp include/ServerSocket.h src/ServerSocket.cpp include/SocketException.h include/Socket.h src/Socket.cpp)
add_library(netry ${SOURCE_FILES})