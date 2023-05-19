/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:26:10 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/08 09:24:24 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

char	*ft_strdup(const char *string)
{
	char	*str;
	char	*save_str;
	size_t	len;

	if (! string)
		return (NULL);
	len = ft_strlen(string);
	str = (char *)malloc(len + 1);
	if (! str)
		return (NULL);
	save_str = str;
	while (*string)
		*str++ = *string++;
	*str = 0;
	return (save_str);
}
