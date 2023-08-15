/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:46:22 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 13:05:01 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_args(format, i, ap);
			i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (print_length);
}

int	ft_args(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (fmt[i + 1] == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long int),
				"0123456789abcdef"));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (fmt[i + 1] == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (fmt[i + 1] == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
