# Makefile for push_swap

# Variables
NAME = push_swap

# Prints DEBUG Messages
DEBUG = 1

# Compiler options
CC = cc
CFLAGS = -Wall -Werror -Wextra -D DEBUG=$(DEBUG)
CLIBS = -L$(LIB_FOLDER) -lft_ft_printf
RM = rm -f

# ->Folders
SRC_FOLDER = ./src/
LIB_FOLDER = ./lib/

# ->Files
LIBFT_FT_PRINTF = $(LIB_FOLDER)/libft_ft_printf.a
SRCS = \
	$(SRC_FOLDER)main.c \
	$(SRC_FOLDER)debug.c \
	$(SRC_FOLDER)push.c \
	$(SRC_FOLDER)swap.c \
	$(SRC_FOLDER)rotate.c \
	$(SRC_FOLDER)reverse_rotate.c \

# Object files
OBJS = $(SRCS:.c=.o)

# TARGETS
.PHONY: $(NAME) all clean fclean re god run

all: $(NAME)

$(NAME): $(LIBFT_FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS)  -o $(NAME)

$(LIBFT_FT_PRINTF):
	make -C $(LIB_FOLDER)
	echo "\nlibft_ft_printf.a compiled!\n"

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_FT_PRINTF) 
	make -C $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) 1 2 3 4 9 8 7 6

god:
	git status
	git add .
	git status
	git commit -m " ->Random Makefile Commit<- "
	git status
