cmake_minimum_required(VERSION 3.16)

project(0042_Creating_a_Simple_QWidget_Window VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(0042_Creating_a_Simple_QWidget_Window
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 0042_Creating_a_Simple_QWidget_Window APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(0042_Creating_a_Simple_QWidget_Window SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(0042_Creating_a_Simple_QWidget_Window
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(0042_Creating_a_Simple_QWidget_Window PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.0042_Creating_a_Simple_QWidget_Window)
endif()
set_target_properties(0042_Creating_a_Simple_QWidget_Window PROPERTIES
    # Надо чтобы испоняемый файл назывался simple_qwidget (проект на Ubuntu)
    OUTPUT_NAME "simple_qwidget"  # <- ДОБАВЬТЕ ЭТУ СТРОКУ
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS 0042_Creating_a_Simple_QWidget_Window
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(0042_Creating_a_Simple_QWidget_Window)
endif()

################################################################################
# Автоматическое создание ярлыка для Wayland во время сборки (только для Linux)
# Проверяем, что сборка идет под Linux
if(UNIX AND NOT APPLE)
    # Название вашего исполняемого таргета (замените my_executable на имя вашей программы в add_executable )
    # Сюда пишем имя из add_executable(имя_таргета ...)
    set(TARGET_NAME 0042_Creating_a_Simple_QWidget_Window)

    # Имя .desktop файла (должно строго совпадать с app.setDesktopFileName в main.cpp)
    # Сюда пишем то, что у вас указано в OUTPUT_NAME
    set(WM_CLASS "simple_qwidget")

    set(DESKTOP_FILE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${WM_CLASS}.desktop")

    # Генерируем содержимое ярлыка с абсолютными путями
    file(WRITE ${DESKTOP_FILE_PATH}
        "[Desktop Entry]\n"
        "Type=Application\n"
        "Name=Simple QWidget (Debug)\n"
        #"Name=Simple QWidget (Debug)\n"
        "Exec=$<TARGET_FILE:${TARGET_NAME}>\n"   # CMake сам подставит правильный путь с учетом OUTPUT_NAME
        #"Icon=${CMAKE_CURRENT_SOURCE_DIR}/icon/web.png\n" # Укажите точный путь к исходному PNG файлу на диске
        "Icon=/home/itsme/studies/qt_Sergey_Budeikin/0042_Creating_a_Simple_QWidget_Window/icon/web.png\n" # Укажите точный путь к исходному PNG файлу на диске
        "Terminal=false\n"
        "StartupWMClass=${WM_CLASS}\n"  # Должно совпадать с OUTPUT_NAME
    )

    # Автоматически копируем ярлык в локальную папку пользователя после сборки таргета
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${DESKTOP_FILE_PATH}" "$ENV{HOME}/.local/share/applications/"
        COMMENT "Копирование .desktop файла для поддержки иконок в Wayland..."
    )
endif()
################################################################################
