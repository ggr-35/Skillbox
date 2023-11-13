cmake_minimum_required(VERSION 3.17)

add_executable(25 main.cpp ${MY_INCLUDE_DIR}/f.h)
target_include_directories(25 PUBLIC ${MY_INCLUDE_DIR})