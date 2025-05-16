cmake_minimum_required(VERSION 3.10)
project(MiniMatchingEngine)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)

add_executable(matching_engine
    src/main.cpp
    src/OrderBook.cpp
)