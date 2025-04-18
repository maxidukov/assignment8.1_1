cmake_minimum_required(VERSION 3.16)

project(assignment8_1__1_QC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(/home/max/libpqxx-7.8.1 pqxx-build)

add_executable(assignment8_1__1_QC main.cpp
    sqlselectquery.h sqlselectquery.cpp
    sqlselectquerybuilder.h sqlselectquerybuilder.cpp
    studentstable.h
    testquery.h
    studentstable.cpp )

target_link_libraries(assignment8_1__1_QC PRIVATE pqxx)

include(GNUInstallDirs)
install(TARGETS assignment8_1__1_QC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
