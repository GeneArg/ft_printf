SRC = ft_printf.c print_num.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) Makefile

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} ${NAME} ${OBJ}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re