cmake_minimum_required(VERSION 3.29)

project(spdlog_test)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14 -O2 -fPIC")

aux_source_directory(./ ALL_SOURCE)
include_directories(${PROJECT_SOURCE_DIR}/third-party/include/)

link_directories(${PROJECT_SOURCE_DIR}/third-party/x64/Release)

add_executable(${PROJECT_NAME} ${ALL_SOURCE})

target_link_libraries(${PROJECT_NAME} spdlog)

  
