cmake_minimum_required(VERSION 2.8)
project(CSTberger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(${CMAKE_HOST_APPLE})
	include_directories(/sw/include)
	link_directories(/sw/lib)
endif(${CMAKE_HOST_APPLE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/usr/local/share/ghaas/include)
link_directories(/usr/local/share/ghaas/lib)

FILE(GLOB sources src/*.C)

add_executable(CSTberger ${sources})
target_link_libraries(CSTberger CM10 m)
