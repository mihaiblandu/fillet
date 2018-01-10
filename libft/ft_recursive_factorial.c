/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:06:55 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 12:28:42 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		result;

	result = 1;
	if ((nb == 0) || (nb == 1))
		return (result);
	if ((nb >= 13) || (nb < 0))
		return (0);
	while ((nb - 1) >= 1)
	{
		result = (nb * ft_recursive_factorial(nb - 1));
		return (result);
	}
	return (result);
}
