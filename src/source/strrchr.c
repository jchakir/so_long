/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:19:15 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/08 14:33:09 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

char	*ft_strrchr(const char *str, char c)
{
	int		len;

	len = ft_strlen(str);
	if (! str)
		return (NULL);
	if (! c)
		return ((char *)str + len);
	while (len--)
		if (str[len] == c)
			return ((char *)str + len);
	return (NULL);
}
