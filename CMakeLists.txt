cmake_minimum_required(VERSION 3.24.1)
project(EDA_Tarea_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code main.cpp include/utils.cpp include/sort.cpp include/time.cpp)
target_include_directories(code PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(code PRIVATE cxx_std_11)