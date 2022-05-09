cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp manager.cpp boss.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Company ${SOURCES})

target_include_directories(Company PUBLIC ${MY_INCLUDE_DIR})