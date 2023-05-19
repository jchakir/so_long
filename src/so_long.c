/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:48:50 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:56:22 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_programme(void)
{
	exit (0);
	return (0);
}

static int	ft_key_hook_for_winning_msg(int keycode)
{
	if (keycode == 53)
		ft_exit_programme();
	return (0);
}

static void	ft_move_ok_and_reset_images(t_setting *setting)
{
	char	*moves_count_str;

	setting->moves_count++;
	moves_count_str = ft_itoa(setting->moves_count);
	mlx_clear_window(setting->mlx, setting->win);
	ft_put_images_to_window(setting);
	mlx_string_put(setting->mlx, setting->win, SCORE_X, \
							SCORE_Y, COLOR_CODE, moves_count_str);
	free(moves_count_str);
}

int	ft_key_hook(int keycode, t_setting *setting)
{
	(void)setting;
	if (keycode == 53)
		ft_exit_programme();
	if (keycode == 0 || keycode == 123)
		if (ft_move_left(setting))
			ft_move_ok_and_reset_images(setting);
	if (keycode == 1 || keycode == 125)
		if (ft_move_down(setting))
			ft_move_ok_and_reset_images(setting);
	if (keycode == 2 || keycode == 124)
		if (ft_move_rigth(setting))
			ft_move_ok_and_reset_images(setting);
	if (keycode == 13 || keycode == 126)
		if (ft_move_up(setting))
			ft_move_ok_and_reset_images(setting);
	return (0);
}

void	ft_winning_message_then_exit(t_setting *setting)
{
	mlx_clear_window(setting->mlx, setting->win);
	mlx_string_put(setting->mlx, setting->win, setting->win_size_x / 3, \
					setting->win_size_y / 2, COLOR_CODE, WINNING_MSG);
	mlx_key_hook(setting->win, ft_key_hook_for_winning_msg, NULL);
	mlx_hook(setting->win, 17, 0L, ft_exit_programme, NULL);
	mlx_loop(setting->mlx);
}
