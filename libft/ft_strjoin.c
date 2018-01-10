/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:03:14 by mperepio          #+#    #+#             */
/*   Updated: 2018/01/10 16:49:10 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*join(char const *s1, char const *s2)
{
	char			*new;
	int				i;
	int				t_length;
	int				size_one;

	i = 0;
	while (s1[i])
		i++;
	size_one = i;
	i = 0;
	while (s2[i])
		i++;
	t_length = size_one + i + 1;
	new = malloc(t_length);
	if (!(new))
		return (NULL);
	i = -1;
	while (++i < size_one)
		new[i] = s1[i];
	while (i < t_length - 1)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) && s2)
	{
		while (s2[i])
			i++;
		return (ft_strsub(s2, 0, i));
	}
	else if (s1 && !(s2))
	{
		while (s1[i])
			i++;
		return (ft_strsub(s1, 0, i));
	}
	return (join(s1, s2));
}
