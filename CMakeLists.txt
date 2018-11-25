cmake_minimum_required(VERSION 3.12)
project(hsp_src)

set(CMAKE_CXX_STANDARD 14)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(lexer token.l "${CMAKE_CURRENT_BINARY_DIR}/token.cc")
bison_target(parser parser.yy "${CMAKE_CURRENT_BINARY_DIR}/parser.cc")

include_directories(./)

add_executable(hsp_src
        node.h
        node.cc
        ${BISON_parser_OUTPUTS}
        ${FLEX_lexer_OUTPUTS}
        main.cpp
        llvs/instructions.cc llvs/instructions.h code_gen.cc code_gen.h llvs/instruction.cc llvs/instruction.h llvs/value.cc llvs/value.h llvs/program.cc llvs/program.h llvs/table.cc llvs/table.h)