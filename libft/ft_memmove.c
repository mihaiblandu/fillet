/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:35:32 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 13:45:45 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	if_overlap(unsigned char *dest, unsigned char *source,
						size_t len, int *flag)
{
	size_t	index;
	size_t	i;
	size_t	m;

	i = 0;
	index = 0;
	while (index < len)
	{
		if (&(source[index]) == &(dest[0]))
			*flag = 1;
		index++;
	}
	m = index;
	while (*flag == 1 && i < m)
	{
		index--;
		dest[index] = source[index];
		i++;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;
	int				flag;

	flag = 0;
	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if_overlap(dest, source, len, &flag);
	while (flag == 0 && i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
