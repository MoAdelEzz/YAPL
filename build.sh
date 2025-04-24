#!/bin/bash

# Build and run the Flex/Bison calculator example with C++

# Check for required commands
for cmd in flex bison g++; do
    if ! command -v $cmd &> /dev/null; then
        echo "Error: $cmd is not installed"
        exit 1
    fi
done

# Generate parser and lexer files
echo "Generating parser and lexer..."
bison -d lex-yacc/parser.ypp -o src/parser.tab.cpp --defines=include/parser.tab.hpp -Wcounterexample
flex -o src/lex.yy.cc lex-yacc/lexer.l 

# Compile the program
echo "Compiling the program..."
g++ -std=c++17 -o yapl \
    -Iinclude \
    src/parser.tab.cpp \
    src/lex.yy.cc \
    src/branching.cpp \
    src/controllers.cpp \
    src/expression.cpp \
    src/common.cpp \
    src/functions.cpp \
    src/loop.cpp \
    -lfl

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful. Running calculator..."
    echo "-------------------------------------"
    ./yapl
else
    echo "Build failed."
    exit 1
fi