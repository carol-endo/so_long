/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:14:31 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/05/27 15:12:19 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	size_t	i;

	if (n == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		i = n;
		if (i >= 10)
			ft_putnbr_fd(i / 10, fd);
		digit = (i % 10) + '0';
		ft_putchar_fd(digit, fd);
	}
}
