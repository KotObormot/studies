cmake_minimum_required(VERSION 3.17)

add_executable(${PROJECT_NAME} main.cpp math.cpp ${MY_INCLUDE_DIR}/math.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
