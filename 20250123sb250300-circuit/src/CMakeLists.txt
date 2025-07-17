cmake_minimum_required(VERSION 3.17)

add_executable(${PROJECT_NAME} main.cpp ${M_INCLUDE_DIR}/mmath.h mmath.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${M_INCLUDE_DIR})