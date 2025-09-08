cmake_minimum_required(VERSION 3.20)
project(WappenheimVector)

add_library(WappenheimVector)
target_include_directories(WappenheimVector
    PUBLIC
        include)
target_sources(WappenheimVector
    PRIVATE
        vector.c)