/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:08:27 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/29 19:14:27 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_length(char *dst, int *flag, size_t size)
{
	size_t	length;

	length = 0;
	while (dst[length])
	{
		if (length == size)
		{
			*flag = 1;
			break ;
		}
		length++;
	}
	return (length);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_one;
	size_t	size_two;
	size_t	index1;
	size_t	index2;
	int		flag;

	flag = 0;
	size_one = 0;
	size_two = 0;
	index2 = 0;
	index1 = find_length(dst, &flag, size);
	size_one = index1;
	while (src[size_two])
		size_two++;
	while (src[index2] && (index1 + 1 < size))
		dst[index1++] = src[index2++];
	if (flag != 1)
		dst[index1] = '\0';
	return (size_one + size_two);
}
