cmake_minimum_required(VERSION 3.1)
project(yavl-cpp
        LANGUAGES CXX
        VERSION 0.1)       

find_package(yaml-cpp REQUIRED)

add_library(yavl-cpp
            include/yavl.h
            yavl.cpp)

target_include_directories(yavl-cpp
                            PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)               

target_link_libraries(yavl-cpp
                            PUBLIC yaml-cpp)

add_subdirectory(example-code)

if(BUILD_TESTING)
        add_subdirectory(test)
endif()
