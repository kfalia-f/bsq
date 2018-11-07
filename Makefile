# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:24:10 by kfalia-f          #+#    #+#              #
#    Updated: 2018/11/07 19:56:19 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SOURCE = -L. -lft

FNS = srcs/ft_*.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(NAME).c $(FNS) $(SOURCE)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
