cmake_minimum_required(VERSION 3.10)

project(BakcylProgramowanie)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include(External_GTest.cmake)

# SRC
include_directories(Source)
add_subdirectory(Source)
include_directories(Map/Include)
add_subdirectory(Map/Source)
include_directories(Combat/Include)
add_subdirectory(Combat/Source)
include_directories(zadania)
add_subdirectory(zadania)
add_subdirectory(zadania/Test)

# TEST
include_directories(Test)
add_subdirectory(Test)
include_directories(Map/Test)
add_subdirectory(Map/Test)
include_directories(Combat/Test)
add_subdirectory(Combat/Test)

add_library(source_objects_lib OBJECT ${SOURCES})

add_executable(bakcyl_programowania $<TARGET_OBJECTS:source_objects_lib>
                             "main.cpp")

 target_link_libraries(bakcyl_programowania 	${GTEST_MAIN_LIBRARY}
                                                 ${GTEST_LIBRARY}
                                                 ${GMOCK_MAIN_LIBRARY}
                                                 ${GMOCK_LIBRARY})

set(TEST_BINARY_FILES $<TARGET_OBJECTS:source_objects_lib>
                      ${TEST_FILES}
                      ${MAIN_TEST})

add_executable(bakcyl_programowania_UT ${TEST_BINARY_FILES})
target_link_libraries(bakcyl_programowania_UT 	${GTEST_MAIN_LIBRARY}
                                       		${GTEST_LIBRARY}
                                       		${GMOCK_MAIN_LIBRARY}
                                       		${GMOCK_LIBRARY})

# Valgrind
find_program(VALGRIND "valgrind")
if(VALGRIND)
target_link_libraries(bakcyl_programowania_UT LINK_PUBLIC)
add_custom_target(valgrind COMMAND "${VALGRIND}" --tool=memcheck
                                                 --leak-check=yes
                                                 --show-reachable=yes
                                                 --num-callers=20
                                                 --track-fds=no
                                                 --track-origins=yes
                                                 --error-exitcode=1
                                                 $<TARGET_FILE:bakcyl_programowania_UT>)
endif()
