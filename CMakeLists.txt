cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0074 NEW)    # respect <PACKAGE>_ROOT variables in "find_package"
include(CMakePrintHelpers)

set(CMAKE_CXX_STANDARD 17)

# Add paths to check for cmake modules:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(bottle_label_taskSample VERSION 1.0)
find_package(pylon 8.0.0 REQUIRED)
find_package(pylonDataProcessing 3.0.0 REQUIRED)

add_executable(bottle_label_taskSample
    RecipeSample.cpp
    bottle_label_task.precipe
    ResultData.h
    OutputObserver.h
)

get_filename_component(PYLON_RECIPE
    "${CMAKE_CURRENT_SOURCE_DIR}/bottle_label_task.precipe" ABSOLUTE
)

target_compile_definitions(bottle_label_taskSample
        PRIVATE
        PYLON_RECIPE="${PYLON_RECIPE}"
        )

target_link_libraries(bottle_label_taskSample
    PRIVATE
    pylon::pylon
    pylon::DataProcessing
)

install( TARGETS bottle_label_taskSample )