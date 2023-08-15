/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:10:05 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/05/27 16:32:20 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && j < ft_count_word(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		str[j] = (char *)malloc(sizeof(char) * (ft_len(s, c, i) + 1));
		while (s[i] != c && s[i] != '\0')
			str[j][k++] = s[i++];
		str[j][k] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}
