cmake_minimum_required(VERSION 3.18.4)

project(FileStringsSorting)

add_executable("${PROJECT_NAME}" main.c
                                 src/conversion.c
                                 src/files.c
                                 src/types_split.c
                                 src/utils.c)
include_directories(include)

