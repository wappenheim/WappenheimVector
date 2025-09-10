cmake_minimum_required(VERSION 3.20)
project(WappenheimVector)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

set(DEFAULT_BUILD_TYPE "Release")

if(BUILD_SHARED_LIBS)
    add_library(WappenheimVector SHARED)
else()
    add_library(WappenheimVector STATIC)
endif()

set_property(TARGET WappenheimVector PROPERTY C_STANDARD 90)
target_include_directories(WappenheimVector
    PUBLIC
        include)
target_sources(WappenheimVector
    PRIVATE
        vector.c)