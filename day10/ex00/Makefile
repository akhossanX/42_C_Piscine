# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 20:42:05 by akhossan          #+#    #+#              #
#    Updated: 2019/03/07 12:05:52 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c 

OBJECTS = ft_putchar.o ft_swap.o ft_putstr.o ft_strcmp.o ft_strlen.o 

HEADERS = includes/

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(SRC) -I$(HEADERS)
	ar rc $(NAME) $(OBJECTS) 
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
