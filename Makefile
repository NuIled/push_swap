CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC= push_swap.c soter.c ft_memcmp.c createlist.c ft_strdup.c  ft_strlen.c ft_atoi.c ft_strlcpy.c ft_substr.c ft_strnstr.c \

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