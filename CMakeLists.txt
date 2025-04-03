cmake_minimum_required(VERSION 3.28)
project(YAPL)

# add_custom_target(
#         GenerateGrammar ALL
#         COMMAND ${CMAKE_SOURCE_DIR}/grammar/generate.sh
#         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#         COMMENT "grammar generation..."
# )

# add_dependencies(Cmm GenerateGrammar)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_C_COMPILER "${CMAKE_CXX_COMPILER}")

file(GLOB PARSER_HPP_SRC "${CMAKE_SOURCE_DIR}/lib/*.hpp")
file(GLOB PARSER_CPP_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB PARSER_CC_SRC "${CMAKE_SOURCE_DIR}/src/*.cc")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(yapl ${PARSER_HPP_SRC} ${PARSER_CPP_SRC} ${PARSER_CC_SRC})