/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:05:39 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:05:39 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>

int	fn_handle(char symbol, va_list params)
{
	if (symbol == 'c')
		return (ft_putchar(va_arg(params, int)));
	else if (symbol == '%')
		return (ft_putchar('%'));
	else if (symbol == 's')
		return (ft_putstr(va_arg(params, char *), 0));
	else if (symbol == 'd' || symbol == 'i')
		return (ft_handle_int(va_arg(params, int)));
	else if (symbol == 'u')
		return (ft_handle_unsigned(va_arg(params, unsigned int)));
	else if (symbol == 'p')
		return (ft_handle_ptr(va_arg(params, size_t)));
	else if (symbol == 'x')
		return (ft_handle_hex(va_arg(params, unsigned int), 0));
	else if (symbol == 'X')
		return (ft_handle_hex(va_arg(params, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	params;
	char	*v_symbols;

	i = 0;
	printed = 0;
	v_symbols = "cspdiuxX%";
	va_start(params, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr(v_symbols, format[i + 1]))
		{
			printed += fn_handle(format[i + 1], params);
			format += 2;
		}
		else
			printed += ft_putchar(format[i++]);
	}
	va_end(params);
	return (printed);
}
