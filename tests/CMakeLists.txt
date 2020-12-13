cmake_minimum_required(VERSION 3.18.4)

project(FileStringsSortingUnitTest)

add_executable("${PROJECT_NAME}" main.c
                                 src/test_types_split.c
                                 ../src/types_split.c
                                 src/test_utils.c
                                 ../src/utils.c)
include_directories(include
                    ../include)

