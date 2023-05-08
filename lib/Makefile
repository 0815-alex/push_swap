# Makefile for libft.a

# Compiler options
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Library name and source files
NAME = libft_ft_printf.a
SRC_FOLDER = ./src/
SRCS = $(SRC_FOLDER)ft_isalpha.c \
	$(SRC_FOLDER)ft_isdigit.c \
	$(SRC_FOLDER)ft_isalnum.c \
	$(SRC_FOLDER)ft_isascii.c \
	$(SRC_FOLDER)ft_isprint.c \
	$(SRC_FOLDER)ft_strlen.c \
	$(SRC_FOLDER)ft_memset.c \
	$(SRC_FOLDER)ft_bzero.c \
	$(SRC_FOLDER)ft_memcpy.c \
	$(SRC_FOLDER)ft_memmove.c \
	$(SRC_FOLDER)ft_strlcpy.c \
	$(SRC_FOLDER)ft_strlcat.c \
	$(SRC_FOLDER)ft_toupper.c \
	$(SRC_FOLDER)ft_tolower.c \
	$(SRC_FOLDER)ft_strchr.c \
	$(SRC_FOLDER)ft_strrchr.c \
	$(SRC_FOLDER)ft_strncmp.c \
	$(SRC_FOLDER)ft_memchr.c \
	$(SRC_FOLDER)ft_memcmp.c \
	$(SRC_FOLDER)ft_strnstr.c \
	$(SRC_FOLDER)ft_atoi.c \
	$(SRC_FOLDER)ft_calloc.c \
	$(SRC_FOLDER)ft_strdup.c \
	$(SRC_FOLDER)ft_substr.c \
	$(SRC_FOLDER)ft_strjoin.c \
	$(SRC_FOLDER)ft_strtrim.c \
	$(SRC_FOLDER)ft_split.c \
	$(SRC_FOLDER)ft_itoa.c \
	$(SRC_FOLDER)ft_strmapi.c \
	$(SRC_FOLDER)ft_striteri.c \
	$(SRC_FOLDER)ft_putchar_fd.c \
	$(SRC_FOLDER)ft_putstr_fd.c \
	$(SRC_FOLDER)ft_putendl_fd.c \
	$(SRC_FOLDER)ft_putnbr_fd.c \
	$(SRC_FOLDER)ft_lstnew.c \
	$(SRC_FOLDER)ft_lstadd_front.c \
	$(SRC_FOLDER)ft_lstsize.c \
	$(SRC_FOLDER)ft_lstlast.c \
	$(SRC_FOLDER)ft_lstadd_back.c \
	$(SRC_FOLDER)ft_lstdelone.c \
	$(SRC_FOLDER)ft_lstclear.c \
	$(SRC_FOLDER)ft_lstiter.c \
	$(SRC_FOLDER)ft_lstmap.c \
	$(SRC_FOLDER)ft_printf.c \
	$(SRC_FOLDER)print_char.c \
	$(SRC_FOLDER)print_str.c \
	$(SRC_FOLDER)print_dez_to_hexa.c \
	$(SRC_FOLDER)print_ptr.c \
	$(SRC_FOLDER)print_nbr.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Targets
.PHONY:	all clean fclean re

all: $(NAME) 

$(NAME): $(OBJS)
	ar -crs $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
