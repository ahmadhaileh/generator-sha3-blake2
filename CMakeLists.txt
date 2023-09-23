cmake_minimum_required(VERSION 3.10)

project(PasswordGenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the paths to the local header files
include_directories("${CMAKE_SOURCE_DIR}/libs/libsodium/include" "${CMAKE_SOURCE_DIR}/libs/openssl/include")

add_executable(PasswordGenerator src/main.cpp)

# Link the local libraries
target_link_libraries(PasswordGenerator 
    "${CMAKE_SOURCE_DIR}/libs/libsodium/lib/libsodium.lib"
    "${CMAKE_SOURCE_DIR}/libs/openssl/lib/libcrypto.lib")
