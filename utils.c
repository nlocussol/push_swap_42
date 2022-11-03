/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:43:15 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/03 10:49:32 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_fastest(t_tab_int *tab, int max2, int max)
{
	int	diff_max;
	int	diff_max2;

	diff_max = 0;
	diff_max2 = 0;
	if (max > tab->length_b / 2)
		diff_max = tab->length_b - max;
	else
		diff_max = max;
	if (max2 > tab->length_b / 2)
		diff_max2 = tab->length_b - max2;
	else
		diff_max2 = max2;
	if (diff_max2 > diff_max)
		return (max);
	else
		return (max2);
}

int	find_max2(t_tab_int *tab)
{
	int	i;
	int	max;
	int	max2;

	max = find_min_max_index(tab->pile_b, tab->length_b, 1);
	i = 0;
	max2 = 0;
	while (i != tab->length_b)
	{
		if (max2 != max && tab->pile_b[max2] < tab->pile_b[i]
			&& tab->pile_b[i] < tab->pile_b[max])
			max2 = i;
		else if (max2 == max && tab->pile_b[i] < tab->pile_b[max])
			max2 = i;
		i++;
	}
	return (max2);
}

int	find_min_max_index(int *tab, int length, int min_max)
{
	int	m;
	int	i;
	int	cnt;

	i = 0;
	cnt = 1;
	m = tab[0];
	while (cnt < length)
	{
		if (min_max == 0 && m > tab[cnt])
		{
			m = tab[cnt];
			i = cnt;
		}
		if (min_max == 1 && m < tab[cnt])
		{
			m = tab[cnt];
			i = cnt;
		}
		cnt++;
	}
	return (i);
}

int	nb_chunk(t_tab_int *tab)
{
	int	div;

	div = (tab->length_a / 10) + 15;
	if (tab->length_a % div != 0)
		div = tab->length_a / div + 1;
	else
		div = tab->length_a / div;
	return (div);
}

int	less_max_chunk(t_tab_int *tab, int len_chunk, int cnt, int len_a)
{
	int	i;
	int	chunk;
	int	index;

	i = 0;
	index = (len_chunk * cnt) - 1;
	if (index > len_a)
		index = len_a - 1;
	chunk = tab->cpy[index];
	while (i != tab->length_a)
	{
		if (tab->pile_a[i] <= chunk)
			return (i);
		i++;
	}
	return (-1);
}
