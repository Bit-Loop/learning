cmake_minimum_required(VERSION 3.0)
project(mimeType)

set(CMAKE_C_STANDARD 11)

add_executable(MIME main.c "hashtable.h" "hashtable.c" "testData.c")
