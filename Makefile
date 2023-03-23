# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 21:14:39 by aoutifra          #+#    #+#              #
#    Updated: 2023/03/21 22:57:37 by aoutifra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC= push.c swap.c push_swap.c soter.c createlist.c ft_strdup.c  ft_strlen.c ft_atoi.c ft_strlcpy.c ft_split.c ft_strnstr.c \

HEADER = push_swap.h

OBJ= $(SRC:.c=.o)

NAME= push_swap

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
