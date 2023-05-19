/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:48:21 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:48:11 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_images(t_setting *setting)
{
	int		dim;
	char	*coin_xpm;
	char	*player_xpm;
	char	*wall_xpm;
	char	*door_xpm;

	dim = IMG_X;
	coin_xpm = "images/coin.xpm";
	player_xpm = "images/player.xpm";
	wall_xpm = "images/wall.xpm";
	door_xpm = "images/door.xpm";
	setting->coin = mlx_new_image(setting->mlx, dim, dim);
	setting->coin = mlx_xpm_file_to_image(setting->mlx, coin_xpm, &dim, &dim);
	setting->player = mlx_new_image(setting->mlx, dim, dim);
	setting->player = mlx_xpm_file_to_image(setting->mlx, player_xpm, \
													&dim, &dim);
	setting->wall = mlx_new_image(setting->mlx, dim, dim);
	setting->wall = mlx_xpm_file_to_image(setting->mlx, wall_xpm, &dim, &dim);
	setting->door = mlx_new_image(setting->mlx, dim, dim);
	setting->door = mlx_xpm_file_to_image(setting->mlx, door_xpm, &dim, &dim);
}

static void	ft_put_image_to_win(t_setting *setting, char caracter, int x, int y)
{
	if (caracter == '1')
		mlx_put_image_to_window(setting->mlx, setting->win, \
								setting->wall, x, y);
	else if (caracter == 'P')
		mlx_put_image_to_window(setting->mlx, setting->win, \
								setting->player, x, y);
	else if (caracter == 'C')
		mlx_put_image_to_window(setting->mlx, setting->win, \
								setting->coin, x, y);
	else if (caracter == 'E')
		mlx_put_image_to_window(setting->mlx, setting->win, \
								setting->door, x, y);
}

void	ft_put_images_to_window(t_setting *setting)
{
	char	**map;
	int		x;
	int		y;

	map = setting->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_put_image_to_win(setting, map[y][x], x * IMG_X, y * IMG_Y);
			x++;
		}
		y++;
	}
}
