/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:00:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/08 14:37:40 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_2d_pointer(char *ptr_2D[])
{
	int	i;

	i = 0;
	if (ptr_2D)
	{
		while (ptr_2D[i])
			free(ptr_2D[i++]);
		free(ptr_2D);
	}
}

void	ft_put_error_then_exit(char const *error)
{
	ft_putendl_fd(error, 2);
	exit (EXIT_FAILURE);
}

void	ft_perror_then_exit(char const *error)
{
	perror(error);
	exit (EXIT_FAILURE);
}
