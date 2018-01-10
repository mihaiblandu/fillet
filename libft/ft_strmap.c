/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:39:26 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/29 20:31:55 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = NULL;
	if (!(s) || !(f))
		return (new);
	while (s[i])
		i++;
	new = malloc(i + 1);
	if (!(new))
		return (NULL);
	while (*s)
	{
		new[j] = f(*s);
		s++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
