/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:08:16 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 16:08:18 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				s_len;
	char			*res;
	unsigned int	i;

	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	if (!(res = malloc(sizeof(char) * s_len + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		res[i] = ((*f)(i, *s));
		s++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
