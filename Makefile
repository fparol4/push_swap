CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
# OBJ_DIR is set to SRC_DIR as requested
OBJ_DIR = $(SRC_DIR)

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/ft_args.c \
      $(SRC_DIR)/ft_check.c \
      $(SRC_DIR)/ft_move.c \
      $(SRC_DIR)/ft_option.c \
      $(SRC_DIR)/ft_path.c \
      $(SRC_DIR)/ft_sort.c \
      $(SRC_DIR)/ft_stack_free.c \
      $(SRC_DIR)/ft_target.c \
      $(SRC_DIR)/ft_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
