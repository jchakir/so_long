/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext_and_read_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:48:07 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:46:02 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read_map(char const *map_filepath)
{
	char	*str;
	char	*temp_str;
	char	buff[BUFFER_SIZE + 1];
	int		fd_file;
	int		read_size;

	fd_file = open(map_filepath, O_RDONLY);
	if (fd_file < 0)
		ft_perror_then_exit(map_filepath);
	str = ft_strdup("");
	while (1)
	{
		read_size = read(fd_file, buff, BUFFER_SIZE);
		if (read_size < 0)
			ft_perror_then_exit(map_filepath);
		if (! read_size)
			break ;
		buff[read_size] = '\0';
		temp_str = ft_strjoin(str, buff);
		free(str);
		str = temp_str;
	}
	close(fd_file);
	return (str);
}

char	*ft_check_ext_and_read_map(char const *map_filepath)
{
	char	*map_str;
	char	*file_extention;

	file_extention = ft_strrchr(map_filepath, '.');
	if (! file_extention)
		ft_put_error_then_exit(INVALID_MAP_EXT);
	if (ft_strncmp(file_extention, ".ber", 5))
		ft_put_error_then_exit(INVALID_MAP_EXT);
	map_str = ft_read_map(map_filepath);
	if (ft_strlen(map_str) < 12)
		ft_put_error_then_exit(INVALID_MAP);
	return (map_str);
}
