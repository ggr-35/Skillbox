cmake_minimum_required(VERSION 3.17)

add_executable(25.2 main.cpp ${MY_INCLUDE_DIR}/cpu.h ${MY_INCLUDE_DIR}/disk.h ${MY_INCLUDE_DIR}/kbr.h ${MY_INCLUDE_DIR}/gpu.h)
target_include_directories(25.2 PUBLIC ${MY_INCLUDE_DIR})