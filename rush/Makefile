# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 20:19:31 by lmaron-g          #+#    #+#              #
#    Updated: 2018/11/04 20:19:34 by lmaron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=colle-2
CC=gcc
CFLAGS= -Wall -Werror -Wextra
CDIR=./
HDIR=./
DDIR=./dep/
SOURCE=do_rush.c ft_strcmp.c readtask.c ft_diff.c
OBJECTS=$(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

-include $(addprefix $(DDIR), $(SOURCE:.c=.d))

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
