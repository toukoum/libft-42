NAME = libft.a

DEPS = libft.h

SRC=$(filter-out $(SRC_BONUS), $(wildcard ft_*.c))
OBJ = $(SRC:.c=.o)

SRC_BONUS=$(wildcard ft_lst*.c)
BONUS_OBJ = $(SRC_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ROSE)Creating library $(NAME)...$(NC)"
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(DEPS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	@echo "$(ROSE)Adding bonus functions to $(NAME)...$(NC)"
	ar rcs $(NAME) $(BONUS_OBJ)

$(BONUS_OBJ): $(SRC_BONUS) $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_BONUS)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@echo "$(RED)Cleaning library $(NAME)...$(NC)"
	rm -f $(NAME)

re: fclean all

t: $(NAME) bonus
	@$(CC) $(CFLAGS) main.c -L. -lft -o test
	@./test


.PHONY: all clean fclean re bonus t