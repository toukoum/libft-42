NAME = libft.a

SRC = ft_*.c 
OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lst*.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

$(BONUS_OBJ): $(BONUS_SRC)
	$(CC) $(CFLAGS) -c $(BONUS_SRC)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all