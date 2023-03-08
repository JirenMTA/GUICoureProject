cmake_minimum_required(VERSION 3.20)
project(TryGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
include("/usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake")
find_package(PkgConfig REQUIRED)
pkg_check_modules(MyLib REQUIRED IMPORTED_TARGET MyLib)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(TryGUI main.cpp MainWindow.cpp MainWindow.h WindowRead.cpp WindowRead.h WindowGetRight.cpp WindowGetRight.h WindowGrant.cpp WindowGrant.h)

target_link_libraries(TryGUI
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        PkgConfig::MyLib
        nlohmann_json::nlohmann_json
        )

