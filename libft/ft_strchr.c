/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:37:48 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/08/15 13:05:31 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;	
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
	// while (s[i])
	// {
	// 	if (s[i] == (char)c)
	// 		return ((char *)&s[i]);
	// 	i++;
	// }
	// if ((char)c == '\0')
	// 	return ((char *)&s[i]);
	// return (NULL);