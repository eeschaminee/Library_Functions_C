# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eschamin <eschamin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 14:00:14 by eschamin       #+#    #+#                 #
#    Updated: 2019/11/11 10:54:30 by eschamin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
OBJECTS	=	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
			ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o \
			ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
			ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
			ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
			ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
			ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o \
			ft_lstadd_back.o ft_lstclear.o ft_lstdelone.o ft_lstadd_front.o \
			ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o
FLAGS 	= 	-Wall -Werror -Wextra
INCLUDES=	.
C_GREEN	=	\033[38;5;28m
C_WHITE	=	\033[38;5;7m
C_BLUE	=	\033[38;5;73m
C_GREY	=	\033[38;5;241m

all: $(NAME)

%.o: %.c
	@echo "$(C_GREY)Compiling...		$(C_WHITE)$<"
	@gcc -c -o $@ $< $(FLAGS) -I $(INCLUDES)

$(NAME): $(OBJECTS)
	@echo "$(C_BLUE)Making a library...	$(C_WHITE)$@"
	@ar rcs $(NAME) $(OBJECTS)
	@echo "$(C_GREEN)Done"

clean:
	@echo "$(C_BLUE)Cleaning..."
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -f $(BONUS)
	@echo "$(C_GREEN)Done"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
