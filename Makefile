CC = cc

CFLAGS = -Wall -Werror -Wextra -g -fdiagnostics-color=always

SRC=ft_memcmp.c createlist.c ft_strdup.c  ft_strlen.c ft_atoi.c ft_strlcpy.c ft_substr.c push_swap.c ft_strnstr.c \

HEADER = push_swap.h

OBJ= $(SRC:.c=.o)

NAME= push_swap

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)