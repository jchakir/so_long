/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:32:14 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/04 18:07:25 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*save_r;

	if (! s1)
		s1 = "";
	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (! r)
		return (r);
	save_r = r;
	while (*s1)
		*r++ = *s1++;
	while (*s2)
		*r++ = *s2++;
	*r = 0;
	return (save_r);
}
