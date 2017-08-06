cmake_minimum_required(VERSION 3.8)
project(pbrain_Negato)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pattern.h constant.h Answer.h Cell.h Cell.cpp Answer.cpp Pattern.cpp BitGrid.h BitGrid.cpp Board.h Board.cpp debug__code.h Ai.h Ai.cpp)
add_executable(pbrain_Negato ${SOURCE_FILES})