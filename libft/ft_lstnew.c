/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:59:04 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 15:59:08 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*cell;

	if (!(cell = malloc(sizeof(t_list))))
		return (NULL);
	cell->content = content;
	cell->next = NULL;
	return (cell);
}
