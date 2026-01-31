/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:29:11 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:29:11 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "stdio.h"

char	*ft_padstart(char *str, int max_size, char placeholder)
{
	int		i;
	int		len;
	int		diff;
	char	pad[diff];
	char	*str_wpad;

	len = ft_strlen(str);
	if (len >= max_size)
		return (str);
	diff = max_size - len;
	i = 0;
	while (i < diff)
		pad[i++] = placeholder;
	str_wpad = ft_calloc(max_size + 1, sizeof(len));
	ft_memcpy(str_wpad, pad, diff);
	ft_memcpy(str_wpad + diff, str, len);
	return (str_wpad);
}

int	main(int argc, char *argv[])
{
	char	*x0;

	x0 = ft_padstart("1001", 8, '0');
	printf("x0: %s\n", x0);
	return (0);
}
