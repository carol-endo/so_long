/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:11 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 12:57:40 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*ft_hex_to_str(unsigned int n, const char *base)
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

int	ft_print_hex(unsigned int n, const char *base)
{
	char	*hex;
	int		i;

	hex = ft_hex_to_str(n, base);
	i = ft_strlen(hex);
	ft_putstr(hex);
	free(hex);
	return (i);
}
