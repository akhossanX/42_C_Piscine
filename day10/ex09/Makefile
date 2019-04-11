# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 19:29:23 by akhossan          #+#    #+#              #
#    Updated: 2019/03/07 19:35:20 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_advanced_do-op

SRCS=$(wildcard srcs/*.c)

INCLUDES=includes/

all:$(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(SRCS) -I$(INCLUDES)
	gcc *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
