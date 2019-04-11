# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 18:49:46 by akhossan          #+#    #+#              #
#    Updated: 2019/03/06 20:31:36 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=do-op

FILES=$(wildcard *.c)

OBJECTS=$(wildcard *.o)

all:$(NAME)

$(NAME):
	gcc -c -Werror -Wall -Werror -I. $(FILES)
	gcc  *.o -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
