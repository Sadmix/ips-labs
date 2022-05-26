cmake_minimum_required(VERSION 3.12)

project(IPS)

set(CMAKE_CXX_FLAGS "/debug:all /debug:inline-debug-info /Qopenmp /Qiopenmp")

include_directories(include)

add_subdirectory(ips_hw_1)
add_subdirectory(ips_sem_1)
add_subdirectory(ips_sem_2)
add_subdirectory(ips_sem_3)