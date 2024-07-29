/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:23:34 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/18 07:47:24 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif

int		ft_check_end(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	char	*res;

	i = 0;
	if (s1 == NULL)
	{
		if (!(res = malloc(sizeof(char) * (ft_strlen(s2) + 1))))
			return (NULL);
		while (*s2)
			res[i++] = *s2++;
		res[i] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_soubstr(char *str, int s, int e, int a)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = malloc(sizeof(char) * ((e - s) + 1))))
		return (NULL);
	while (s < e)
		res[i++] = str[s++];
	res[i] = '\0';
	if (a == 1)
		free(str);
	return (res);
}

int		norme(char **str, char **line, int ret)
{
	if (ft_check_end(*str) == -1)
	{
		if (*str == NULL)
		{
			*line = ft_soubstr("", 0, 0, 0);
			return (0);
		}
		*line = *str;
		*str = NULL;
	}
	else
	{
		*line = ft_soubstr(*str, 0, ft_check_end(*str), 0);
		*str = ft_soubstr(*str, ft_check_end(*str) + 1, ft_strlen(*str), 1);
	}
	return (*str == NULL && ret == 0 ? 0 : 1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str = NULL;
	char			*buf;
	int				ret;

	if (!line || !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (ft_check_end(str) == -1 && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str = ft_strjoin2(str, buf);
	}
	free(buf);
	return (norme(&str, &*line, ret));
}
