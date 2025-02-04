##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC	=	my_compute_power_rec.c	\
		my_strlen.c  \
		my_compute_square_root.c  \
		my_find_prime_sup.c  \
		my_get_nbr.c  \
		my_is_prime.c  \
		my_isneg.c  \
		my_put_nbr.c  \
		my_putchar.c  \
		my_putstr.c  \
		my_revstr.c  \
		my_str_isalpha.c  \
		my_str_islower.c  \
		my_str_isnum.c  \
		my_str_isprintable.c	\
		my_strcapitalize.c  \
		my_strcmp.c  \
		my_strcpy.c  \
		my_strlowcase.c  \
		my_strncmp.c  \
		my_strncpy.c  \
		my_strcat.c	\
		my_str_concat.c		\
		my_strstr.c	\
		my_strupcase.c 	\
		my_swap.c	\
		my_getsign.c    \
		my_str_to_word_array_02.c	\
		my_putnbr_base.c	\
		mini_printf.c	\
		my_put_float.c	\
		my_putnbr_e.c	\
		my_putnbr_sc.c	\
		my_put_unsigned.c	\
		my_put_long.c	\
		my_round.c	\
		my_printf.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include
		cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
