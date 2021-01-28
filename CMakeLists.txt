cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmakemodules/)

find_package(GLIB REQUIRED)
find_package(GStreamer REQUIRED)
find_package(GObject REQUIRED)

if(NOT GSTREAMER_FOUND OR NOT GLIB_FOUND OR NOT GOBJECT_FOUND)
	exit()
endif()

include_directories(
	${GSTREAMER_INCLUDE_DIR}
	${GLIB_INCLUDE_DIRS}
	${GOBJECT_INCLUDE_DIR}
)

set(LIBRARIES
	glib-2.0
	gobject-2.0
	gstreamer-1.0
	gstrtspserver-1.0
)
add_executable(basic-tutorial-1 basic-tutorial-1.cpp)
target_link_libraries(basic-tutorial-1 ${LIBRARIES})


add_executable(basic-tutorial-2 basic-tutorial-2.cpp)
target_link_libraries(basic-tutorial-2 ${LIBRARIES})

add_executable(basic-tutorial-3 basic-tutorial-3.cpp)
target_link_libraries(basic-tutorial-3 ${LIBRARIES})

add_executable(basic-tutorial-4 basic-tutorial-4.cpp)
target_link_libraries(basic-tutorial-4 ${LIBRARIES})

add_executable(rtsp-server-test rtsp-server-test.cpp)
target_link_libraries(rtsp-server-test ${LIBRARIES})


