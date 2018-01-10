/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:49:26 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 13:43:59 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destin;

	i = 0;
	source = (unsigned char*)src;
	destin = (unsigned char*)dst;
	while (i < n && source[i] != (unsigned char)c)
	{
		destin[i] = source[i];
		i++;
	}
	if (i == n)
		return (NULL);
	destin[i] = source[i];
	i++;
	return (&destin[i]);
}
