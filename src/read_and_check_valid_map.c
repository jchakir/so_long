/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_valid_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:14:40 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:54:53 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_newlines_and_unauth_chars(char *map_str)
{
	while (*map_str)
	{
		if (*map_str != '1' && *map_str != '0' && *map_str != 'P' && \
			*map_str != 'C' && *map_str != 'E' && *map_str != '\n')
			ft_put_error_then_exit(INVALID_MAP);
		if (*map_str == '\n' && *(map_str + 1) == '\n')
			ft_put_error_then_exit(INVALID_MAP);
		map_str++;
	}
}

static void	ft_check_map_lengths(char **map)
{
	int			map_len;
	int			initial_len;

	map_len = 0;
	while (map[map_len])
		map_len++;
	if (map_len < 3)
		ft_put_error_then_exit(INVALID_MAP);
	initial_len = ft_strlen(*map++);
	if (map_len == 3 && initial_len == 3)
		ft_put_error_then_exit(INVALID_MAP);
	while (*map)
	{
		if (ft_strlen(*map) != initial_len)
			ft_put_error_then_exit(INVALID_MAP);
		map++;
	}
}

static void	ft_check_walls(char **map)
{
	char	*str;
	int		last_char;

	str = *map++;
	last_char = ft_strlen(str) - 1;
	while (*str)
		if (*str++ != '1')
			ft_put_error_then_exit(INVALID_MAP);
	while (*map)
	{
		str = *map;
		if (*str != '1' || str[last_char] != '1')
			ft_put_error_then_exit(INVALID_MAP);
		map++;
	}
	str = *(--map);
	while (*str)
		if (*str++ != '1')
			ft_put_error_then_exit(INVALID_MAP);
}

static void	ft_check_if_thereis_more_than_one(char **map)
{
	char	*str;
	int		c_d_p[3];

	c_d_p[0] = 0;
	c_d_p[1] = 0;
	c_d_p[2] = 0;
	while (*map)
	{
		str = *map;
		while (*str)
		{
			if (*str == 'C')
				c_d_p[0] += 1;
			if (*str == 'E')
				c_d_p[1] += 1;
			if (*str == 'P')
				c_d_p[2] += 1;
			str++;
		}
		map++;
	}
	if (! c_d_p[0] || ! c_d_p[1] || c_d_p[2] != 1)
		ft_put_error_then_exit(INVALID_MAP);
}

char	**ft_read_and_check_valid_map(char const *map_filepath)
{
	char	*map_str;
	char	**map;

	map_str = ft_check_ext_and_read_map(map_filepath);
	ft_check_newlines_and_unauth_chars(map_str);
	map = ft_split(map_str, '\n');
	if (! map)
		ft_perror_then_exit(MALLOC_ERROR);
	free(map_str);
	ft_check_map_lengths(map);
	ft_check_walls(map);
	ft_check_if_thereis_more_than_one(map);
	return (map);
}
