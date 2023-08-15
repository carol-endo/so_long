/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:51:17 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 12:52:58 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned int num)
{
	size_t	i;

	i = 1;
	num /= 10;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	size_t	digits;
	char	*str;

	digits = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
