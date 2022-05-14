cmake_minimum_required(VERSION 3.22)
project(homework32_2)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(homework32_2 main.cpp)
target_link_libraries(homework32_2 PRIVATE nlohmann_json::nlohmann_json)
