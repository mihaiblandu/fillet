/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:16:37 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/25 17:26:21 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	restart(t_array *test_array, t_tetr_list *the_trmo, int a, int b)
{
	test_array->j = a;
	test_array->i = b;
	the_trmo->j = 0;
	the_trmo->i = 0;
	return (-1);
}

static void	go_to_next_row(t_array *test_array, t_tetr_list *the_trmo, int b)
{
	test_array->j++;
	the_trmo->j++;
	the_trmo->i = 0;
	test_array->i = b;
}

int			check_this_area(t_array *test_array, t_tetr_list *trmo, int letter)
{
	int		a;
	int		b;

	a = test_array->j;
	b = test_array->i;
	test_array->i++;
	trmo->i++;
	while (trmo->j != trmo->size)
	{
		if (test_array->j == test_array->size)
			return (restart(test_array, trmo, a, b));
		while (trmo->space[trmo->j][trmo->i] != '\0')
		{
			if ((trmo->space[trmo->j][trmo->i] == letter &&
					test_array->space[test_array->j][test_array->i] != '.')
					|| test_array->i == test_array->size)
				return (restart(test_array, trmo, a, b));
			test_array->i++;
			trmo->i++;
		}
		go_to_next_row(test_array, trmo, b);
	}
	restart(test_array, trmo, a, b);
	return (1);
}

int			find_next_space(t_array *test_array, t_tetr_list *trmo, int letter)
{
	while (test_array->j <= test_array->size - trmo->size &&
							test_array->j < test_array->size)
	{
		while (test_array->i <= test_array->size - trmo->max_length &&
					test_array->i < test_array->size)
		{
			if (test_array->space[test_array->j][test_array->i] == '.' ||
					trmo->space[0][0] == '.')
				if (check_this_area(test_array, trmo, letter) == 1)
					return (1);
			test_array->i++;
		}
		test_array->j++;
		test_array->i = 0;
	}
	return (-1);
}
