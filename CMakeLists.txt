cmake_minimum_required (VERSION 2.6)
project (SmartFridge)

set(SmartFridge_VERSION_MAJOR 0)
set(SmartFridge_VERSION_MINOR 1)

configure_file(
"${PROJECT_SOURCE_DIR}/SmartFridge.h.in"
"${PROJECT_SOURCE_DIR}/SmartFridge.h"
)

find_package(OpenCV REQUIRED)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(SmartFridge SmartFridge.cpp)
target_link_libraries(SmartFridge ${OpenCV_LIBS})