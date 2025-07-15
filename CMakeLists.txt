cmake_minimum_required(VERSION 3.16)

project(pointcloud_viewer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_DIR "C:\\Qt\\Qt-6.9.1")
set(QT_FIND_DIR ${QT_DIR}\\lib\\cmake\\Qt6)
set(QT_BIN_DIR ${QT_DIR}\\bin)
set(QT_PLUGINS_DIR ${QT_DIR}\\plugins)
set(CMAKE_PREFIX_PATH "${QT_FIND_DIR}")
set(CMAKE_AUTOMOC ON)

message(STATUS "Using Qt from: ${QT_FIND_DIR}")

add_subdirectory(deps)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Qml Quick)

set(SOURCES
    src/main.cpp
    src/utils/Singleton.h
    src/ui/Logger.h
    src/ui/Logger.cpp
)


qt_add_executable(pointcloud_viewer
    ${SOURCES}
)

target_include_directories(pointcloud_viewer PRIVATE src)

target_link_libraries(pointcloud_viewer PRIVATE Qt6::Core Qt6::Widgets Qt6::Qml Qt6::Quick)

target_compile_definitions(pointcloud_viewer PRIVATE
    QML_IMPORT_PATH="\"${QT_DIR}/qml\""
)

add_custom_command(TARGET pointcloud_viewer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${QT_BIN_DIR}"
    $<TARGET_FILE_DIR:pointcloud_viewer>
)

add_custom_command(TARGET pointcloud_viewer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${QT_PLUGINS_DIR}"
    $<TARGET_FILE_DIR:pointcloud_viewer>
)

qt_add_resources(pointcloud_viewer "resources"
    PREFIX "/"
    FILES 
    qml/main.qml
    qml/LogPanel.qml
)
