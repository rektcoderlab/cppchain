cmake_minimum_required(VERSION 3.10)
project(SimpleBlockchain)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

add_executable(blockchain
    main.cpp
    Block.cpp
    Blockchain.cpp
)

target_link_libraries(blockchain OpenSSL::SSL OpenSSL::Crypto)

if(MSVC)
    target_compile_options(blockchain PRIVATE /W4)
else()
    target_compile_options(blockchain PRIVATE -Wall -Wextra -pedantic)
endif()
