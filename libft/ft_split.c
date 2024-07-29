/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:07:18 by ramzi             #+#    #+#             */
/*   Updated: 2021/02/17 07:38:43 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_word(char const *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			word++;
		i++;
	}
	return (word);
}

int		word_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	**fill(char **splitted, char const *str, char c, int word)
{
	int i;
	int y;
	int len;

	i = -1;
	while (++i < word)
	{
		while (*str == c)
			str++;
		len = word_len(str, c);
		if (!(splitted[i] = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		y = 0;
		while (y < len)
			splitted[i][y++] = *str++;
		splitted[i][y] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**splitted;

	if (!s)
		return (0);
	word = count_word(s, c);
	if (!(splitted = malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	splitted = fill(splitted, s, c, word);
	return (splitted);
}
