/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:19:38 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 12:27:56 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		result = nb * ft_recursive_power(nb, (power - 1));
		return (result);
	}
	return (result);
}
