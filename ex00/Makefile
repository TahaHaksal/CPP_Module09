NAME = btc

CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard ./src/*.cpp ./src/commands/*.cpp)

OBJ_DIR = ./objects
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo btc created

$(OBJ_DIR)/%.o: ./src/commands/%.cpp
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: ./src/%.cpp
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@$(RM) -rf $(OBJ)

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all
