# Makefile for push_swap

# Variables
NAME = push_swap

# Compiler options
CC = cc
CFLAGS = -Wall -Werror -Wextra 
CLIBS = -L$(LIB_FOLDER) -lft
RM = rm -f

# ->Folders
SRC_FOLDER = ./src/
LIB_FOLDER = ./lib/

# ->Files
LIBFT = $(LIB_FOLDER)/libft.a
SRCS = \
	$(SRC_FOLDER)push_swap.c \
	$(SRC_FOLDER)push.c \
	$(SRC_FOLDER)swap.c \
	$(SRC_FOLDER)rotate.c \
	$(SRC_FOLDER)reverse_rotate.c \

# Object files
OBJS = $(SRCS:.c=.o)

# TARGETS
.PHONY: $(NAME) all clean fclean re god

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIB_FOLDER)
	echo "\nLIBFT compiled!\n"

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT) 
	make -C $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

god:
	git status
	git add .
	git status
	git commit -m " ->Random Makefile Commit<- "
	git status
