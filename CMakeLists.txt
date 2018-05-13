cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER_FILES "include")
set(STATIC_LIBRARY "curl")
set(SOURCE_FILES "src")

project(fetchyt)
include_directories(${HEADER_FILES})
file(GLOB SOURCES ${SOURCE_FILES}/*)

add_executable(
  fetchyt
  ${SOURCES}
)

find_library(LIB_LOCATION ${STATIC_LIBRARY})
target_link_libraries(fetchyt ${LIB_LOCATION})
