cmake_minimum_required(VERSION 3.10)

project(BakcylProgramowanie)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include(External_GTest.cmake)

# SRC
include_directories(Map/Include)
add_subdirectory(Map/Source)
include_directories(Combat/Cards/Include)
add_subdirectory(Combat/Cards/Source)
include_directories(Combat/Profesja/Include)
add_subdirectory(Combat/Profesja/Source)
include_directories(Combat/Decks/Include)
add_subdirectory(Combat/Decks/Source)
include_directories(Combat/Table/Include)
add_subdirectory(Combat/Table/Source)

# TEST
include_directories(Map/Test)
add_subdirectory(Map/Test)
include_directories(Combat/Cards/Test)
add_subdirectory(Combat/Cards/Test)
include_directories(Combat/Profesja/Test)
add_subdirectory(Combat/Profesja/Test)
include_directories(Combat/Decks/Test)
add_subdirectory(Combat/Decks/Test)
include_directories(Combat/Table/Test)
add_subdirectory(Combat/Table/Test)

add_library(source_objects_lib OBJECT ${SOURCES})

add_executable(bakcyl_programowania $<TARGET_OBJECTS:source_objects_lib>
                             "main.cpp")

set(TEST_BINARY_FILES $<TARGET_OBJECTS:source_objects_lib>
                      ${TEST_FILES}
                      ${MAIN_TEST})

add_executable(bakcyl_programowania_UT ${TEST_BINARY_FILES})
target_link_libraries(bakcyl_programowania_UT 	${GTEST_MAIN_LIBRARY}
                                                ${GTEST_LIBRARY}
                                                ${GMOCK_MAIN_LIBRARY}
                                                ${GMOCK_LIBRARY})

set(CURSES_BUNDLE_DIR "${PROJECT_BINARY_DIR}/ncurses-prefix/src/ncurses")
set(CURSES_INCLUDE_DIR "${CURSES_BUNDLE_DIR}/include/")
set(CURSES_LIBRARIES "${CURSES_BUNDLE_DIR}/lib/libncurses.a")
message(STATUS "Using bundled ncurses in '${CURSES_BUNDLE_DIR}'")

ExternalProject_Add(
                ncurses
                URL "https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.2.tar.gz"
                URL_MD5 "e812da327b1c2214ac1aed440ea3ae8d"
                CONFIGURE_COMMAND ./configure --without-cxx --without-cxx-binding --without-ada --without-manpages --without-progs --without-tests --with-terminfo-dirs=/etc/terminfo:/lib/terminfo:/usr/share/terminfo
                BUILD_COMMAND ${CMD_MAKE}
                BUILD_IN_SOURCE 1
                INSTALL_COMMAND "")

ExternalProject_Get_Property(ncurses source_dir)
set(CURSES_INCLUDE_DIRS ${source_dir}/ncurses/include)

target_link_libraries(bakcyl_programowania ${CURSES_LIBRARIES})
target_link_libraries(bakcyl_programowania_UT ${CURSES_LIBRARIES})
add_dependencies(bakcyl_programowania ncurses)
