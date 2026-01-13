CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98
NAME = rpn

SRCS = main.cpp rpn.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
