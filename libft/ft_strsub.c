/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:48:52 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/29 20:39:34 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	count;

	count = 0;
	new = NULL;
	if (!(s))
		return (new);
	new = malloc(len + 1);
	if (!(new))
		return (NULL);
	while (count < len)
	{
		new[count] = s[start];
		count++;
		start++;
	}
	new[count] = '\0';
	return (new);
}
