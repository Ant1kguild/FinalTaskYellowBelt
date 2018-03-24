cmake_minimum_required(VERSION 3.9)
project(FinalTaskYellowBelt)

set(CMAKE_CXX_STANDARD 17)

add_executable(FinalTaskYellowBelt main.cpp token.cpp token.h condition_parser.cpp condition_parser.h condition_parser_test.cpp date.cpp date.h date_parser.cpp date_parser_test.cpp date_conversion.cpp test_runner.cpp test_runner.h database.cpp database.h node.cpp node.h comparison.h logical_operation.h date_comparing_test.cpp)