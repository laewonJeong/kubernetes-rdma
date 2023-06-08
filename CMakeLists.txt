cmake_minimum_required(VERSION 3.5)

project(test)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_COMPILER "/usr/bin/mpic++")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/threadpool)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/network)

add_executable (test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

target_link_libraries(test PRIVATE lib)
target_link_libraries(test PRIVATE threadpool)
target_link_libraries(test PRIVATE network)
#target_link_libraries(test PRIVATE OpenMP::OpenMP_CXX)
target_compile_features(test PRIVATE cxx_std_17)
