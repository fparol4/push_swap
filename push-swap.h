/* -- LIBS (C) -- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* -- LIBS (EXT) -- */
# include "./lib/libft/libft.h"

/* -- HEADERS -- */
# include "./types/ft_mov.h"
# include "./types/ft_stack.h"

/* -- GENERAL -- */
typedef struct s_pswap
{
	t_stack *sa;
	t_stack *sb;
	t_stack *path; // t_stack<t_path>
} s_pswap;

/* -- FILES -- */
/* src/fr_movn.c */
const char	*ft_movn(e_mov mov);
