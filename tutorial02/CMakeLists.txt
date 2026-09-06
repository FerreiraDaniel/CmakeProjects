cmake_minimum_required(VERSION 3.16..3.24)
project(our_project VERSION 0.0.1
                    DESCRIPTION "Our first project"
)
set(FOO "foo" CACHE STRING "Description of foo")
message(STATUS "Value of FOO:${FOO}")
#For boolean-like variables
#we can use a shorter command:
option(OPTION_1 "Description" OFF)
option(OPTION_2 "Description" ON)