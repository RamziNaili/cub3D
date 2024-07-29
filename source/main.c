/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:48:49 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 07:42:07 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_player	player;

	fd = open(argv[1], O_RDONLY);
	player.bmp = 0;
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
			player.bmp = 1;
		else
			display_err(3);
	}
	if (argc != 2 && argc != 3)
		display_err(3);
	check_name(argv[1]);
	parcing(fd, &player);
	ft_map_pos(&player);
	if (!(player.z_buffer = malloc(sizeof(double) * (player.resolution[0]))))
		return (-1);
	raycasting(&player);
	return (0);
}
