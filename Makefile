# Makefile for push_swap and tester

# Variables
NAME = push_swap
NAME_CHECKER = checker

# Compiler options
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
CLIBS = -L$(LIBFT_FOLDER) -lft -lm
CINCLUDES  = -I$(INCLUDE_FOLDER) 
RM = rm -f

# Color codes
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m

# ->Folders
SRC_FOLDER = ./src/
SRC_FOLDER_CHECKER = ./src_checker/
OBJS_FOLDER = ./obj/
OBJS_FOLDER_CHECKER = ./obj_checker/
LIB_FOLDER = ./lib/
LIBFT_FOLDER = $(LIB_FOLDER)libft/
INCLUDE_FOLDER = ./include/

# ->Files
LIBFT = $(LIBFT_FOLDER)libft.a
BANNER = $(LIBFT_FOLDER)make_banner.sh
SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	check_argv.c \
	debug.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	stack.c \
	stack_utils.c \
	choose_solver.c \
	sort_radix.c \
	sort_small.c \
	sort_best_friend.c \
	sort_best_friend_utils.c)

SRCS_CHECKER = $(addprefix $(SRC_FOLDER_CHECKER), \
	main.c \
	checker_utils.c)

# Object files
OBJS = $(SRCS:$(SRC_FOLDER)%.c=$(OBJS_FOLDER)%.o)
OBJS_CHECKER = $(SRCS_CHECKER:$(SRC_FOLDER_CHECKER)%.c=$(OBJS_FOLDER_CHECKER)%.o)

# TARGETS
.PHONY:	$(NAME) all clean fclean re test check

all: MSG_START $(NAME) MSG_DONE

check: all $(NAME_CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(CLIBS) $(CINCLUDES) -o $(NAME)

$(NAME_CHECKER): $(OBJS) $(OBJS_CHECKER) $(LIBFT)
	@$(CC) $(OBJS_CHECKER) $(filter-out $(OBJS_FOLDER)main.o, $(OBJS)) $(CFLAGS) $(CLIBS) $(CINCLUDES) -o $(NAME_CHECKER)
	@echo "$(GREEN)\n$(NAME_CHECKER): created\n$(RESET)"

$(OBJS_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir -p $(@D)
	@echo -n "$(ORANGE).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_FOLDER_CHECKER)%.o: $(SRC_FOLDER_CHECKER)%.c
	@mkdir -p $(@D)
	@echo -n "$(ORANGE).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_FOLDER)

clean:
	@make --no-print-directory -C $(LIBFT_FOLDER) clean
	@$(RM) $(OBJS)
	@$(BANNER) $(NAME) "removed object files" "$(RED)"
	@$(RM) $(OBJS_CHECKER)
	@$(BANNER) $(NAME_CHECKER) "removed object files" "$(RED)"

fclean: clean
	@make --no-print-directory -C $(LIBFT_FOLDER) fclean
	@$(RM) $(NAME)
	@$(BANNER) $(NAME) "removed program" "$(RED)"
	@$(RM) $(NAME_CHECKER)
	@$(BANNER) $(NAME_CHECKER) "removed program" "$(RED)"

re: fclean all

test: check
	./tests/test_1_to_5.sh

MSG_START:
	@$(BANNER) $(NAME) compiling "$(ORANGE)"

MSG_DONE:
	@$(BANNER) $(NAME) compiled "$(GREEN)"