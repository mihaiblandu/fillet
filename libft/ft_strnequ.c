/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:19:33 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/26 20:41:03 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (!(s1) && !(s2))
		return (1);
	else if ((!(s1) && s2) || (s1 && !(s2)))
		return (0);
	else
		while (s1[i] && s2[i] && i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	if ((i != n) && ((!(s1[i]) && s2[i]) || (s1[i] && (!(s2[i])))))
		return (0);
	return (1);
}
