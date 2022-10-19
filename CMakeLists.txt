cmake_minimum_required (VERSION 2.6)

project(myproject)

file(GLOB "${PROJECT_NAME}_SOURCES" "src/*.cpp")

set(CMAKE_CXX_FLAGS "-Wall -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL, "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE, "-O4 -DNDEBUG")

# Compiler-specific C++11 activation.
# http://stackoverflow.com/questions/10984442/how-to-detect-c11-support-of-a-compiler-with-cmake
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
  execute_process(
    COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
  if (NOT (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7))
    message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.7 or greater.")
  endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
  message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)