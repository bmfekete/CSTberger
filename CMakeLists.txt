cmake_minimum_required(VERSION 3.10)
project(CSTberger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(${GHAASDIR})
    include_directories(${GHAASDIR}/include)
    link_directories(${GHAASDIR}/lib)
else(${GHAASDIR})
    include_directories(/usr/local/share/ghaas/include)
    link_directories(/usr/local/share/ghaas/lib)
endif(${GHAASDIR})

foreach(loop_var surveying instrument)
    add_executable(CST${loop_var} src/CST${loop_var}.c)
    target_include_directories(CST${loop_var} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(CST${loop_var} CM30 m)
    install (TARGETS CST${loop_var} RUNTIME DESTINATION ghaas/bin)
endforeach(loop_var)