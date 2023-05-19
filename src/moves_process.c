/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:51:11 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:53:31 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_setting *setting)
{
	char	**map;
	int		x;
	int		y;

	map = (setting)->map;
	x = setting->player_x;
	y = setting->player_y;
	if (map[y - 1][x] == 'C')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		setting->player_y--;
		setting->coin_count--;
	}
	else if (map[y - 1][x] == '0')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		setting->player_y--;
	}
	else if (map[y - 1][x] == 'E' && ! setting->coin_count)
		ft_winning_message_then_exit(setting);
	else
		return (0);
	return (1);
}

int	ft_move_down(t_setting *setting)
{
	char	**map;
	int		x;
	int		y;

	map = (setting)->map;
	x = setting->player_x;
	y = setting->player_y;
	if (map[y + 1][x] == 'C')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		setting->player_y++;
		setting->coin_count--;
	}
	else if (map[y + 1][x] == '0')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		setting->player_y++;
	}
	else if (map[y + 1][x] == 'E' && ! setting->coin_count)
		ft_winning_message_then_exit(setting);
	else
		return (0);
	return (1);
}

int	ft_move_rigth(t_setting *setting)
{
	char	**map;
	int		x;
	int		y;

	map = (setting)->map;
	x = setting->player_x;
	y = setting->player_y;
	if (map[y][x + 1] == 'C')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		setting->player_x++;
		setting->coin_count--;
	}
	else if (map[y][x + 1] == '0')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		setting->player_x++;
	}
	else if (map[y][x + 1] == 'E' && ! setting->coin_count)
		ft_winning_message_then_exit(setting);
	else
		return (0);
	return (1);
}

int	ft_move_left(t_setting *setting)
{
	char	**map;
	int		x;
	int		y;

	map = (setting)->map;
	x = setting->player_x;
	y = setting->player_y;
	if (map[y][x - 1] == 'C')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		setting->player_x--;
		setting->coin_count--;
	}
	else if (map[y][x - 1] == '0')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		setting->player_x--;
	}
	else if (map[y][x - 1] == 'E' && ! setting->coin_count)
		ft_winning_message_then_exit(setting);
	else
		return (0);
	return (1);
}
