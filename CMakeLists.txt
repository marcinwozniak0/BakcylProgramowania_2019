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
include_directories(Source)
add_subdirectory(Source)
include_directories(Map/Include)
add_subdirectory(Map/Source)
<<<<<<< HEAD
include_directories(Combat/Include)
add_subdirectory(Combat/Source)
=======
include_directories(Cards/Include)
add_subdirectory(Cards/Source)
>>>>>>> 32cba4e7a8ad79ce154752f74686e95d0d88a499

# TEST
include_directories(Test)
add_subdirectory(Test)
include_directories(Map/Test)
add_subdirectory(Map/Test)
<<<<<<< HEAD
include_directories(Combat/Test)
add_subdirectory(Combat/Test)
=======
include_directories(Cards/Test)
add_subdirectory(Cards/Test)
>>>>>>> 32cba4e7a8ad79ce154752f74686e95d0d88a499

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
