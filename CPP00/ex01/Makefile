NAME	= phonebook

CC		= c++ -std=c++98
FLAGS	= -Wall -Werror -Wextra -fsanitize=address

SRC		= *.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re