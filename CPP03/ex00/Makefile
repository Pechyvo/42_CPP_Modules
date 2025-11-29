NAME	= ../clap

CC		= c++ -std=c++98
FLAGS	= -Wall -Werror -Wextra

ifdef DEBUG
FLAGS += -DDEBUG
endif

SRC		= $(wildcard *.cpp)
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re