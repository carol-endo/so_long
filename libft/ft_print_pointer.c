/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:56 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 12:58:30 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned long n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

static char	*ft_hex_to_str(unsigned long n, const char *base)
{
	int		size;
	char	*hex;

	size = ft_hex_len(n);
	hex = malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (hex);
}

int	ft_print_pointer(unsigned long int n, char *base)
{
	size_t	len;
	char	*hex;

	if (n == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		len = ft_hex_len(n);
		hex = ft_hex_to_str(n, base);
		ft_putstr("0x");
		if (hex)
		{
			ft_putstr(hex);
			free(hex);
		}
		else
		{
			ft_putstr("(null)");
			return (6);
		}
		return (len + 2);
	}
}
