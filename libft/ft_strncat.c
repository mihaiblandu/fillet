/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:53:56 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/24 19:05:55 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	count;

	count = 0;
	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k] && count != n)
	{
		s1[i] = s2[k];
		count++;
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
