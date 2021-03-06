/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:28:26 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/29 20:07:41 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (!(s))
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	ft_putchar('\n');
}
