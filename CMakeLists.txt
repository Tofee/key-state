project(key-state)
cmake_minimum_required(VERSION 3.0)

add_executable(key-state main.c)
install(TARGETS key-state DESTINATION bin)
