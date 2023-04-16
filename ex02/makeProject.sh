#!/bin/bash

# Parse command line arguments
if [ $# -ne 1 ]; then
  echo "Usage: $0 <name>"
  exit 1
fi

name=$1

# Create directories
mkdir src include objects

# Create Makefile
cat > Makefile << EOF
NAME = $name

CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = \$(wildcard ./src/*.cpp ./src/commands/*.cpp)

OBJ_DIR = ./objects
OBJ = \$(addprefix \$(OBJ_DIR)/,\$(notdir \$(SRC:.cpp=.o)))

all: \$(NAME)

\$(NAME): \$(OBJ)
	@\$(CC) \$(FLAGS) \$(OBJ) -o \$(NAME)
	@echo $name created

\$(OBJ_DIR)/%.o: ./src/commands/%.cpp
	@\$(CC) \$(FLAGS) -c -o \$@ \$<

\$(OBJ_DIR)/%.o: ./src/%.cpp
	@\$(CC) \$(FLAGS) -c -o \$@ \$<

clean:
	@\$(RM) -rf \$(OBJ)

fclean: clean
	@\$(RM) -rf \$(NAME)

re: fclean all
EOF

# Create generic cpp main file
cat > src/main.cpp << EOF
#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
EOF
