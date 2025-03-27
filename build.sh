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
bison -d parser.ypp
flex -o lex.yy.cc lexer.l

# Compile the program
echo "Compiling the program..."
g++ -std=c++17 -o yapl \
    parser.tab.cpp \
    lex.yy.cc \
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