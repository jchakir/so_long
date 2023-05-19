/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:52:37 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:57:24 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "source/source.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 10
# define IMG_X 60
# define IMG_Y 60
# define COLOR_CODE 65280
# define SCORE_X 20
# define SCORE_Y 20
# define INVALID_MAP "invalid map"
# define INVALID_MAP_EXT "invalid map extention, must end whith '.ber'"
# define MALLOC_ERROR "malloc() error"
# define INVALID_ARGS "Invalid Arguments"
# define WIN_TITLE "So Long Game"
# define WINNING_MSG "You Win, Press 'esp' to exit"

typedef struct s_setting
{
	void	*mlx;
	void	*win;
	char	**map;
	int		win_size_x;
	int		win_size_y;
	void	*player;
	void	*coin;
	void	*wall;
	void	*door;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		moves_count;
}	t_setting;

void	ft_put_error_then_exit(char const *error);
void	ft_perror_then_exit(char const *error);
char	**ft_read_and_check_valid_map(char const *map_filepath);
void	ft_set_images(t_setting *setting);
void	ft_put_images_to_window(t_setting *setting);
char	*ft_check_ext_and_read_map(char const *map_filepath);
void	ft_free_2d_pointer(char *ptr_2D[]);
void	ft_winning_message_then_exit(t_setting *setting);
int		ft_move_up(t_setting *setting);
int		ft_move_down(t_setting *setting);
int		ft_move_rigth(t_setting *setting);
int		ft_move_left(t_setting *setting);
int		ft_key_hook(int keycode, t_setting *setting);
void	ft_set_initial_values(t_setting *setting);
void	ft_winning_message_then_exit(t_setting *setting);
int		ft_exit_programme(void);

#endif
