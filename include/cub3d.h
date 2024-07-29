/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:38:33 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:16:19 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef	struct		s_sprite
{
	double			x;
	double			y;
}					t_sprites;

typedef struct		s_texture
{
	void			*text;
	char			*text_data;
	int				text_h;
	int				text_w;
	int				text_sl;
	int				text_sb;
	int				text_ed;
}					t_texture;

typedef struct		s_map
{
	int				x;
	int				y;
	int				max_x;
	int				max_y;
	char			p;
}					t_map;

typedef	struct		s_win
{
	int				bmp;
	int				color_s;
	int				resolution[2];
	int				if_map;
	int				end_map;
	char			**map;
	char			*tmp;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	unsigned int	f;
	unsigned int	c;
	t_map			map_p;
	int				index_texture;
	void			*mlx;
	void			*win;
	double			old_plane_x;
	double			old_dir_x;
	double			pos_x;
	double			dir_x;
	double			dir_y;
	double			pos_y;
	double			camera_x;
	double			plane_x;
	double			plane_y;
	double			rot_speed;
	double			move_speed;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	int				hit;
	int				side;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	t_texture		tex[8];
	double			*z_buffer;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				sprite_width;
	int				stripe;
	t_sprites		*sprites;
	double			*tab_sprite;
	double			*sprite_distance;
	int				tab_key[10];
	int				num_sprite;
}					t_player;

void				ft_map_pos(t_player *parse);
void				ft_print_map(t_player *parse);
void				display_err(int code);
int					if_correct_line(char *str);
int					is_space(char c);
void				ft_max(t_player *parse);
void				check_around(t_player *parse, int x, int y);
void				check_side(t_player *parse);
void				check_map(t_player *parse);
void				player(t_player *parse);
void				ft_init_struct(t_player *parse);
int					create_trgb(int t, int r, int g, int b);
int					is_num(char c);
int					empty_line(char *str);
int					ft_stock_trgb(char *str);
int					ft_resolution(char *str, t_player *parse);
int					ft_wparam(char *str, t_player *parse);
void				ft_stock_map(char *str, t_player *parse);
void				ft_tronc(char **str);
void				ft_test_double(char *str);
void				ft_test_param(t_player *parse);
int					n_string(char *str);
void				raycasting(t_player *player);
void				ft_print_struct(t_player *parse);
void				my_mlx_pixel_put(t_player *player, int x,
		int y, unsigned int color);
int					ft_exit(t_player *player);
int					move(t_player *player);
void				init_win(t_player *player);
void				init_var_dda(t_player *player, int i);
void				init_var_dda2(t_player *player);
void				dda_algo(t_player *player);
void				draw_calcul(t_player *player);
void				side_texture(t_player *player);
void				draw_ceilling(t_player *player, int i);
void				draw_tex_wall(t_player *player, int i);
void				draw_floor(t_player *player, int i);
int					main_loop(t_player *player);
void				init_pos(t_player *player);
void				init_tab(t_player *player);
void				init_var(t_player *player);
void				texture_init(t_player *player);
int					pressed_key(int keycode, t_player *player);
void				help_n_release(t_player *player, int keycode);
int					released_key(int keycode, t_player *player);
void				raycasting(t_player *player);
void				display_err(int code);
void				ft_max(t_player *parse);
void				check_around(t_player *parse, int x, int y);
void				check_side(t_player *parse);
void				check_map(t_player *parse);
void				normed_if_player(t_player *parse, char c, int i, int y);
void				player(t_player *parse);
void				check_size(t_player *parse);
void				ft_map_pos(t_player *parse);
void				ft_stock_map(char *str, t_player *parse);
void				ft_tronc(char **str);
void				ft_test_double(char *str);
void				ft_test_param(t_player *parse);
int					n_string(char *str);
void				ft_print_struct(t_player *parse);
void				ft_print_map(t_player *parse);
void				ft_init_struct(t_player *parse);
int					create_trgb(int t, int r, int g, int b);
int					is_space(char c);
int					is_num(char c);
int					empty_line(char *str);
int					ft_stock_trgb(char *str);
int					ft_resolution(char *str, t_player *parse);
void				normed_wparam(char *str, t_player *parse);
int					ft_wparam(char *str, t_player *parse);
void				test_parse(t_player *parse);
void				launcher(char *str, t_player *parse);
int					check_xpm(char *str);
void				test_xpm(t_player *parse);
void				parcing(int fd, t_player *parse);
void				check_name(char *str);
void				init_var_dda_2(t_player *player);
void				s_sprite(t_player *player);
void				sprite_calcul(t_player *player, int i);
void				draw_sprite(t_player *player);
void				ft_swap_sprites(t_player *player);
void				sort_sprites(t_player *player);
void				ft_sprite(t_player *player);
void				camera_right(t_player *player, int i);
void				camera_left(t_player *player, int i);
void				ft_create_bmp(t_player *player);
void				ft_fill_bmp(t_player *player, int fd);
void				ft_img_header(t_player *player, int fd);
void				ft_bmp_header(t_player *player, int fd);
void				test_rgb(int r, int g, int b);
void				ft_normed_param(char *str, t_player *parse);
void				test_screen_size(t_player *player);

#endif
