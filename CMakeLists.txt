project(ECS)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_VERBOSE_MAKEFILE OFF)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

include_directories(${GLIB2_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDEDIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

link_directories(${GLIB2_LIBRARY_DIRS} ${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS})

aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${GLIB2_LIBRARIES})
target_compile_options(${PROJECT_NAME} PUBLIC ${GLIB2_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_IMAGE_CFLAGS_OTHER})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fms-extensions -Wall -pedantic -std=c11")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DDEBUG=${DEBUG})
