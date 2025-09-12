cmake_minimum_required(VERSION 3.20)
project(WappenheimVector)

include(CTest)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTING "Testing support" ON)

set(DEFAULT_BUILD_TYPE "Release")

if(BUILD_SHARED_LIBS)
    add_library(Vector SHARED)
else()
    add_library(Vector STATIC)
endif()

set_property(TARGET Vector PROPERTY C_STANDARD 90)
target_include_directories(Vector
    PUBLIC
        include)
target_sources(Vector
    PRIVATE
        vector.c)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()