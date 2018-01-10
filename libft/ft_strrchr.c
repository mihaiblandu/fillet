/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:00:34 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 13:52:36 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*back;

	back = NULL;
	while (*s)
	{
		if (*s == (char)c)
			back = (char*)s;
		s++;
	}
	if (*s == (char)c)
		back = (char*)s;
	if (back)
		return (back);
	return (NULL);
}
