cmake_minimum_required(VERSION 3.10)

add_executable(Computer main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp ../include/main.h)
target_include_directories(Computer PUBLIC ${MY_INCLUDE_DIR})

