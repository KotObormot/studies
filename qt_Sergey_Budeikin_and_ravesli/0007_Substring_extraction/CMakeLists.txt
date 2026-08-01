cmake_minimum_required(VERSION 3.16)

project(0007_Substring_extraction LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
#find_package(Qt6 COMPONENTS Core5Compat REQUIRED)

add_executable(0007_Substring_extraction
  main.cpp
)
target_link_libraries(0007_Substring_extraction PRIVATE Qt${QT_VERSION_MAJOR}::Core)
#target_link_libraries(0007_Substring_extraction PRIVATE Qt6::Core5Compat)

include(GNUInstallDirs)
install(TARGETS 0007_Substring_extraction
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
