cmake_minimum_required(VERSION 3.16)

project(0043_Cursor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        cursors.cpp
        cursors.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(0043_Cursor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 0043_Cursor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(0043_Cursor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(0043_Cursor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(0043_Cursor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.0043_Cursor)
endif()
set_target_properties(0043_Cursor PROPERTIES    
    OUTPUT_NAME "cursor"  # <- ДОБАВЬТЕ ЭТУ СТРОКУ
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS 0043_Cursor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(0043_Cursor)
endif()

################################################################################
# Автоматическое создание ярлыка для Wayland во время сборки (только для Linux)
if(UNIX AND NOT APPLE)
    # Название вашего исполняемого таргета из add_executable
    set(TARGET_NAME 0043_Cursor)

    # Имя WM_CLASS и .desktop файла
    set(WM_CLASS "cursor")

    # Сначала готовим шаблон текста (без генератора путей в file WRITE)
    set(DESKTOP_FILE_TEMPLATE "${CMAKE_CURRENT_BINARY_DIR}/${WM_CLASS}.desktop.in")
    set(DESKTOP_FILE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${WM_CLASS}.desktop")

    file(WRITE ${DESKTOP_FILE_TEMPLATE}
        "[Desktop Entry]\n"
        "Type=Application\n"
        "Name=Cursor (Debug)\n"
        "Exec=$<TARGET_FILE:${TARGET_NAME}>\n" # Теперь это безопасно, так как ниже идет GENERATE
        "Icon=${CMAKE_CURRENT_SOURCE_DIR}/icon/web.png\n"
        "Terminal=false\n"
        "StartupWMClass=${WM_CLASS}\n"
    )

    # ВАЖНО: file(GENERATE) заставит CMake правильно раскрыть $<TARGET_FILE:...>
    file(GENERATE
        OUTPUT "${DESKTOP_FILE_PATH}"
        INPUT "${DESKTOP_FILE_TEMPLATE}"
    )

    # Автоматически копируем уже готовый и раскрытый ярлык в локальную папку пользователя после сборки
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${DESKTOP_FILE_PATH}" "$ENV{HOME}/.local/share/applications/"
        COMMENT "Копирование раскрытого .desktop файла для поддержки иконок в Wayland..."
    )
endif()
################################################################################
