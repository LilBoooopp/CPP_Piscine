NAME = megaphone
CC = c++
RM = rm -rf
FLAGS = -Werror -Wextra -Wall -std=c++98

SRC = megaphone.cpp

#--------------------------------------COLORS---------------------------------->

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

#--------------------------------------RULES-----------------------------------#

all:$(SRC) $(NAME)

$(NAME): $(SRC)
		@echo $(CURSIVE)$(GRAY) " - Compiling $(NAME)..." $(NONE)
		@$(CC) $(FLAGS) $(SRC) -o $(NAME)
		@echo $(GREEN)"- Compiled -"$(NONE)

clean:
		@echo $(CURSIVE)$(GRAY) " -> Cleaning object files.." $(NONE)
		@$(RM) $(OBJ)

fclean: clean
		@echo $(CURSIVE)$(GRAY) " -> Removing $(NAME)" $(NONE)
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
