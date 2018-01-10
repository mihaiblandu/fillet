/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:23:13 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/24 16:33:31 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	count;
	char	*new;

	i = 0;
	count = 0;
	while (s1[i])
	{
		count++;
		i++;
	}
	new = malloc(count + 1);
	if (!(new))
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
