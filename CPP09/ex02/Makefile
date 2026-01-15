CC = c++
FLAGS = -std=c++98 -Werror -Wextra -Wall 
NAME = PmergeMe

SRCS = main.cpp pmergeme.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
