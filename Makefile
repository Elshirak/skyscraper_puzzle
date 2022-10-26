
NAME = 	puzzle

HEADER = lib.h
SRC = main.c func.c check_views.c check_directions.c ft_solve.c 
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Wpedantic -fsanitize=address

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ \n$(RESET)\c"
	@cc $(CFLAGS) $(HEADER) -o $(NAME) $(OBJ)
	@echo "\n$(NAME): $(BLUE) $(NAME) created \n$(RESET)"

obj:
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ \n$(RESET)\c"
	@cc $(CFLAGS) -c $(SRC) $(HEADER)
	@echo "\n$(NAME): $(BLUE) object files are created \n$(RESET)"

clean:  
	@rm -rf $(OBJ)
	@echo "$(NAME): $(PINK) object files are deleted $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm lib.h.gch
	@echo "$(NAME): $(PINK) $(NAME) deleted $(RESET)"

re: fclean all
