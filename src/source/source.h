/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:03:53 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/10 13:45:16 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char const *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, char c);
char	*ft_strdup(const char *string);
char	*ft_itoa(int num);

#endif
