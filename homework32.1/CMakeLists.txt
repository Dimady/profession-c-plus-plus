cmake_minimum_required(VERSION 3.22)
project(homework32_1)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(homework32_1 main.cpp)
target_link_libraries(homework32_1 PRIVATE nlohmann_json::nlohmann_json)

