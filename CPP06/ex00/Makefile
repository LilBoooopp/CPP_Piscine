CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98
NAME = convert

SRCS = main.cpp ScalarConverter.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
