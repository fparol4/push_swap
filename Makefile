CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/ft_args.c \
      $(SRC_DIR)/ft_check.c \
      $(SRC_DIR)/ft_chunk.c \
      $(SRC_DIR)/ft_move.c \
      $(SRC_DIR)/ft_option.c \
      $(SRC_DIR)/ft_path.c \
      $(SRC_DIR)/ft_sort.c \
      $(SRC_DIR)/ft_stack_free.c \
      $(SRC_DIR)/ft_target.c \
      $(SRC_DIR)/ft_utils.c

OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
