cmake_minimum_required(VERSION 3.17)

add_executable(${PROJECT_NAME} main.cpp
               ${INCLUDE_DIR}/branch.h branch.cpp 
               ${INCLUDE_DIR}/forest.h forest.cpp 
#               ${INCLUDE_DIR}/numeri.h numeri.cpp         
               )
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
