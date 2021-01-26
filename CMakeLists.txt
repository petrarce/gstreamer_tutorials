cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmakemodules/)

find_package(GLIB REQUIRED)
find_package(GStreamer REQUIRED)
if(NOT GSTREAMER_FOUND OR NOT GLIB_FOUND)
	exit()
endif()

include_directories(
	${GSTREAMER_INCLUDE_DIR}
	${GLIB_INCLUDE_DIRS}
)

add_subdirectory(task1/)

add_executable(basic-tutorial-2 basic-tutorial-2.cpp)
target_link_libraries(basic-tutorial-2 gstreamer-1.0)
