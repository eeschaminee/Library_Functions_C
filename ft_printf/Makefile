# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eschamin <eschamin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 14:00:14 by eschamin       #+#    #+#                 #
#    Updated: 2020/01/08 12:42:38 by eschamin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c puthex.c convert_char.c count_nbr.c convert_nbr.c \
			print_width_precision.c print_nbr.c ft_strlen.c parse.c \
			protected_putchar.c protected_putnbr.c
OBJECTS	=	$(SRC:.c=.o)
FLAGS 	= 	-Wall -Wextra -g
HEADER	=	.
C_GREEN	=	\033[38;5;28m
C_WHITE	=	\033[38;5;7m
C_BLUE	=	\033[38;5;73m
C_GREY	=	\033[38;5;241m

all: $(NAME)

$(NAME) : $(OBJECTS)
	@echo "$(C_GREEN)Making Library$(C_WHITE)"
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@echo "$(C_GREY)Compiling...		$(C_WHITE)$<"
	@gcc $(FLAGS) -o $@ -c $<  -I$(HEADER)

clean:
	@echo "$(C_BLUE)Cleaning..."
	@/bin/rm -f $(OBJECTS)
	@echo "$(C_GREEN)Done"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
