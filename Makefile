NAME    = ?
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     = ?
OBJS 		= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
