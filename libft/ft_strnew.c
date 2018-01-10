/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:57:06 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/02 19:38:38 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	str = malloc(size * sizeof(char) + 1);
	if (!(str))
		return (NULL);
	while (index < size)
	{
		*str = '\0';
		str++;
		index++;
	}
	*str = '\0';
	str = str - index;
	return (str);
}
