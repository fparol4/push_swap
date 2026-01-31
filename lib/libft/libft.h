/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:29:11 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:29:11 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_node
{
	int				*value;
	int				index;
	int				rank;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_stack
{
	int				id;
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_stack;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);

int					ft_atoi(const char *str);
int					ft_vatoi(char *str);
long long			ft_atoll(const char *str);
int					ft_signal(int v);
int					ft_abs(int v);
size_t				ft_digits(size_t v, int size);
char				*ft_itoa(int n);
char				*ft_itoab(size_t v, char *base);
char				*ft_itoab_uns(size_t v, char *base);

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);

size_t				ft_putchar_fd(char c, int fd);
size_t				ft_putstr_fd(char *s, int fd);
size_t				ft_putendl_fd(char *s, int fd);
size_t				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *node);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

t_stack				*ft_stack_new(int id, t_node *node);
void				ft_stack_add_head(t_stack *stack, t_node *node);
void				ft_stack_add_tail(t_stack *stack, t_node *node);
void				ft_stack_rot(t_stack *stack);
void				ft_stack_revrot(t_stack *stack);
void				ft_stack_swap(t_stack *stack);
t_node				*ft_stack_pop_head(t_stack *stack);
t_node				*ft_stack_pop_tail(t_stack *stack);

#endif
