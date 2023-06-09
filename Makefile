# Makefile for push_swap

# Variables
NAME = push_swap

# Prints DEBUG Messages
DEBUG = 1

# Compiler options
CC = cc
CFLAGS = -D DEBUG=$(DEBUG) -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope
CLIBS = -L$(LIB_FOLDER) -lft_printf -lm
CINCLUDES  = -I$(INCLUDE_FOLDER) 
RM = rm -f

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
RESET = \033[0m

# ->Folders
SRC_FOLDER = ./src/
OBJS_FOLDER = ./obj/
LIB_FOLDER = ./lib/
INCLUDE_FOLDER = ./include/

# ->Files
LIBFT_PRINTF = $(LIB_FOLDER)/libft_printf.a
SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	stack.c \
	stack_utils.c \
	choose_solver.c \
	sort_radix.c)

# Object files
OBJS = $(SRCS:$(SRC_FOLDER)%.c=$(OBJS_FOLDER)%.o)

# TARGETS
.PHONY:	$(NAME) all clean fclean re god r

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF)
	@$(CC) $(OBJS) $(CFLAGS) -D DEBUG=$(DEBUG) $(CLIBS) $(CINCLUDES) -o $(NAME)
	@echo "$(GREEN)\n$(NAME): created\n$(RESET)"

$(OBJS_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir -p $(@D)
	@echo -n "."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PRINTF):
	@echo "$(ORANGE)\ncompiling: $(LIBFT_PRINTF)\n$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIB_FOLDER) DEBUG=$(DEBUG)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)$(NAME): cleaned object files$(RESET)"

fclean: clean
	@make --no-print-directory -C $(LIB_FOLDER) fclean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME): cleaned program$(RESET)"

re: fclean all

god:
	git status
	git add .
	git status
	git commit -m " -> Makefile Commit <- "
	git status

r: re
	./$(NAME) 8 4 1 2 5
