/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:49:49 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 12:55:57 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = ft_putstr(str);
	free(str);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	str = ft_utoa(n);
	i = ft_putstr(str);
	free(str);
	return (i);
}
