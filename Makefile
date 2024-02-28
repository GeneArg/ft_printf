CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c print_num.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re