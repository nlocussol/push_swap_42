/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:29:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/02 23:42:51 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_max_index(int *tab, int length, int min_max)
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

int	check_sort(t_tab_int *tab)
{
	int i;

	i = 0;
	while (i != tab->length_a - 1)
	{
		if (tab->pile_a[i] > tab->pile_a[i + 1])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	check_sort_min(t_tab_int *tab)
{
	int	i;
	int	index;
	int	first_a;

	first_a = find_min_max_index(tab->pile_a, tab->length_a, 0);
	index = first_a;
	i = first_a;
	while (i < tab->length_a + first_a - 1)
	{
		if (index == tab->length_a - 1 && first_a != 0)
		{
			if (tab->pile_a[index] > tab->pile_a[0])
				return (0);
			index = 0;
		}
		if (tab->pile_a[index] > tab->pile_a[index + 1])
			return (index + 1);
		index++;
		i++;
	}
	return (-1);
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

void	sort_pb(t_tab_int *tab, t_list_move **tab_move, int len_chunk, int cnt, int len_a)
{
	int	index;
	int	chunk_index;
	int	nb_check;

	index = less_max_chunk(tab, len_chunk, cnt, len_a);
	chunk_index = (len_chunk * cnt) - 1;
	if (chunk_index > len_a)
	{
		chunk_index = (len_a - (len_chunk * (cnt - 1))) / 2;
		chunk_index += (len_chunk * (cnt -1));
	}
	else
		chunk_index = ((len_chunk * (cnt - 1) + chunk_index) / 2);
	nb_check = tab->pile_a[index];
	while (tab->pile_a[0] != nb_check)
	{
		if (index <= tab->length_a / 2)
			r_movement(tab, tab_move, "ra");
		else
			rr_movement(tab, tab_move, "rra");
	}
	p_move_all(tab, tab_move, "pb");
	if (tab->pile_b[0] <= tab->cpy[chunk_index] && tab->length_b > 1)
		r_movement(tab, tab_move, "rb");
}

int find_max2(t_tab_int *tab)
{
	int	i;
	int	max;
	int	max2;

	max = find_min_max_index(tab->pile_b, tab->length_b, 1);
	i = 0;
	max2 = 0;
	while (i != tab->length_b)
	{
		if (max2 != max && tab->pile_b[max2] < tab->pile_b[i] && tab->pile_b[i] < tab->pile_b[max])
			max2 = i;
		else if (max2 == max && tab->pile_b[i] < tab->pile_b[max])
			max2 = i; 
		i++;
	}
	return (max2);
}

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

void	sort_algo(t_tab_int *tab)
{
	int			max_b;
	int			i;
	int			len_chunk;
	int			chunk;
	int			cnt;
	int			len;
	int			max;
	int			len_a;
	int			nb_check;
	t_list_move *tab_move;

	if (check_sort(tab) == -1 || tab->length_a == 1)
	{
		ft_free(tab);
		exit(0);
	}
	len_a = tab->length_a; 
	ft_sort_int_tab(tab->cpy, tab->length_a);
	len_chunk = (tab->length_a / 10) + 15;
	cnt = 0;
	chunk = nb_chunk(tab);
	len = len_chunk;
	tab_move = NULL;
	while (cnt != chunk)
	{
		i = 0;
		cnt++;
		if (len_chunk > tab->length_a)
			len = tab->length_a;
		while (i != len)
		{
			sort_pb(tab, &tab_move, len_chunk, cnt, len_a);
			i++;
		}
	}
	max = 0;
	while (tab->length_b != 0)
	{
		i = find_max2(tab);
		max_b = find_min_max_index(tab->pile_b, tab->length_b, 1);
		if (i != -1 && check_fastest(tab, i, max_b) == i && max == 0)
		{
			nb_check = tab->pile_b[i];
			while (tab->pile_b[0] != nb_check)
			{
				if (i <= tab->length_b / 2)
					r_movement(tab, &tab_move, "rb");
				else
					rr_movement(tab, &tab_move,  "rrb");
			}
			p_move_all(tab, &tab_move, "pa");
			max = 1;
		}
		else
		{
			while (tab->pile_b[max_b] != tab->pile_b[0])
			{
				if (max_b <= tab->length_b / 2)
					r_movement(tab, &tab_move, "rb");
				else
					rr_movement(tab, &tab_move,  "rrb");
				max_b = find_min_max_index(tab->pile_b, tab->length_b, 1);
			}
			p_move_all(tab, &tab_move, "pa");
			if (max == 1)
				s_move(tab, &tab_move, "sa");
			max = 0;
		}
	}
	put_move(&tab_move);
}
