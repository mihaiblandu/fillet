/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:03:18 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/26 17:54:46 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	if (!(s1) && !(s2))
		return (1);
	else if ((!(s1) && s2) || (s1 && !(s2)))
		return (0);
	else
		while (*s1 && *s2)
		{
			if (*s1 == *s2)
			{
				s1++;
				s2++;
			}
			else
				return (0);
		}
	if (!(*s1) && !(*s2))
		return (1);
	return (0);
}
