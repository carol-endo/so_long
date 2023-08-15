/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:00:40 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/05/27 16:40:34 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int num)
{
	size_t	i;

	i = 1;
	if (num < 0)
		i++;
	num /= 10;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(char *str, size_t i, unsigned int num,
		unsigned int is_negative)
{
	str[i] = '\0';
	while (i--)
	{
		str[i] = num % 10 + '0';
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			digits;
	unsigned int	is_negative;
	char			*str;

	digits = ft_numlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	return (ft_convert(str, digits, (unsigned int)n, is_negative));
}
