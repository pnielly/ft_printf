# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 13:04:58 by pnielly           #+#    #+#              #
#    Updated: 2019/12/14 18:20:37 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ./ft_printf.c ./ft_decompose.c ./ft_flag.c ./ft_packing.c ./ft_packing2.c ./ft_packing3.c ./ft_packing4.c ./ft_cvs.c ./ft_convertbase.c ./ft_utils.c ./ft_utils_2.c ./ft_utils_3.c ./ft_utils_4.c ./ft_utils_5.c 
OBJ = ./ft_printf.o ./ft_decompose.o ./ft_flag.o ./ft_packing.o ./ft_packing2.o ./ft_packing3.o ./ft_packing4.o ./ft_cvs.o ./ft_convertbase.o ./ft_utils.o ./ft_utils_2.o ./ft_utils_3.o ./ft_utils_4.o ./ft_utils_5.o
HEADER = libftprintf.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):fclean
	gcc $(FLAGS) -c $(SRC) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:	fclean
	gcc $(FLAGS) -c $(SRC) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o *.gch

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
