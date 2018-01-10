/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:36:35 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/30 18:43:02 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	new = NULL;
	if (!(s) || !(f))
		return (new);
	while (s[i])
		i++;
	new = malloc(i + 1);
	if (!(new))
		return (NULL);
	i = 0;
	while (*s)
	{
		new[j] = f(i, *s);
		s++;
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
