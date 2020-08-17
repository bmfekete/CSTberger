cmake_minimum_required(VERSION 2.8)
project(CSTberger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(${GHAASDIR})
    include_directories(${GHAASDIR}/include)
    link_directories(${GHAASDIR}/lib)
else(${GHAASDIR})
    include_directories(/usr/local/share/ghaas/include)
    link_directories(/usr/local/share/ghaas/lib)
endif(${GHAASDIR})

FILE(GLOB sources src/*.C)

add_executable(CSTberger ${sources})
target_link_libraries(CSTberger CM30 m)
target_include_directories(CSTberger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install (TARGETS CSTberger RUNTIME DESTINATION ghaas/bin)
