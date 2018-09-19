cmake_minimum_required(VERSION 3.8)
project(unit-test)
SET(CMAKE_BUILD_TYPE Debug)

################################
# GTest
################################

ADD_SUBDIRECTORY(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

################################
# Unit Tests
################################

# Add test cpp file
add_executable(runUnitTests ${CMAKE_CURRENT_SOURCE_DIR}/unit-test/PointTest.cpp 
                            ${CMAKE_CURRENT_SOURCE_DIR}/unit-test/main.cpp)
                            
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)

if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEF:my_defs.def /NODEFAULTLIB")
endif()
