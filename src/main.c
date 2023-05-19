/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:39:08 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:50:10 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_initial_values(t_setting *setting)
{
	int		x;
	int		y;

	y = 0;
	setting->coin_count = 0;
	while (setting->map[y])
	{
		x = 0;
		while (setting->map[y][x])
		{
			if (setting->map[y][x] == 'C')
				setting->coin_count++;
			else if (setting->map[y][x] == 'P')
			{
				setting->player_x = x;
				setting->player_y = y;
			}
			x++;
		}
		y++;
	}
	setting->moves_count = 0;
	setting->win_size_x = x * IMG_X;
	setting->win_size_y = y * IMG_Y;
}

int	main(int ac, char **av)
{
	t_setting	*setting;

	if (ac != 2)
		ft_put_error_then_exit(INVALID_ARGS);
	setting = malloc(sizeof(t_setting));
	if (! setting)
		ft_perror_then_exit(MALLOC_ERROR);
	setting->map = ft_read_and_check_valid_map(av[1]);
	ft_set_initial_values(setting);
	setting->mlx = mlx_init();
	ft_set_images(setting);
	setting->win = mlx_new_window(setting->mlx, setting->win_size_x, \
									setting->win_size_y, WIN_TITLE);
	ft_put_images_to_window(setting);
	mlx_string_put(setting->mlx, setting->win, SCORE_X, \
									SCORE_Y, COLOR_CODE, "0");
	mlx_key_hook(setting->win, ft_key_hook, setting);
	mlx_hook(setting->win, 17, 0L, ft_exit_programme, setting);
	mlx_loop(setting->mlx);
	return (0);
}
