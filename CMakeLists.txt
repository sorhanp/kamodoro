cmake_minimum_required(VERSION 3.0.0)

project(kamodoro VERSION 0.0.1 LANGUAGES CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
include(CTest)
enable_testing()

include(CPack)

# Check if gtkmm is installed
find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(GTKMM gtkmm-3.0)
else()
    message(ERROR "GTKMM NOT FOUND")
endif()

add_subdirectory(src)
add_subdirectory(test)