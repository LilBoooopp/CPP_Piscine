CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

NAME = bsp

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
