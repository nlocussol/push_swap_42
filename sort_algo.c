/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:29:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/03 16:11:45 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_max2(t_tab_int *tab, t_list_move **tab_move, int i)
{
	int	nb_check;

	nb_check = tab->pile_b[i];
	while (tab->pile_b[0] != nb_check)
	{
		if (i <= tab->length_b / 2)
			r_movement(tab, tab_move, "rb");
		else
			rr_movement(tab, tab_move, "rrb");
	}
	p_move_all(tab, tab_move, "pa");
	return (1);
}

int	put_max(t_tab_int *tab, t_list_move **tab_move, int max_b, int max)
{
	while (tab->pile_b[max_b] != tab->pile_b[0])
	{
		if (max_b <= tab->length_b / 2)
			r_movement(tab, tab_move, "rb");
		else
			rr_movement(tab, tab_move, "rrb");
		max_b = find_min_max_index(tab->pile_b, tab->length_b, 1);
	}
	p_move_all(tab, tab_move, "pa");
	if (max == 1)
		s_move(tab, tab_move, "sa");
	return (0);
}

void	sort_pb(t_tab_int *tab, t_list_move **tab_move, int cnt, int len_chunk)
{
	int	index;
	int	chunk_index;
	int	nb_check;

	index = less_max_chunk(tab, len_chunk, cnt, tab->static_length_a);
	chunk_index = (len_chunk * cnt) - 1;
	if (chunk_index > tab->static_length_a)
	{
		chunk_index = (tab->static_length_a - (len_chunk * (cnt - 1))) / 2;
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

void	sort_with_chunk(t_tab_int *tab, t_list_move **tab_move)
{
	int	cnt;
	int	len_chunk;
	int	len;
	int	chunk;
	int	i;

	chunk = nb_chunk(tab);
	cnt = 0;
	len_chunk = (tab->length_a / 10) + 15;
	len = len_chunk;
	while (cnt != chunk)
	{
		i = 0;
		cnt++;
		if (len_chunk > tab->length_a)
			len = tab->length_a;
		while (i != len)
		{
			sort_pb(tab, tab_move, cnt, len_chunk);
			i++;
		}
	}
}

void	sort_algo(t_tab_int *tab)
{
	int			max_b;
	int			max;
	int			max2;
	t_list_move	*tab_move;

	if (check_sort(tab) == -1 || tab->length_a == 1)
		ft_free(tab);
	tab_move = NULL;
	if (tab->length_a < 4)
		special_sort(tab, &tab_move);
	ft_sort_int_tab(tab->cpy, tab->length_a);
	sort_with_chunk(tab, &tab_move);
	max = 0;
	while (tab->length_b != 0)
	{
		max2 = find_max2(tab);
		max_b = find_min_max_index(tab->pile_b, tab->length_b, 1);
		if (max2 != -1 && check_fastest(tab, max2, max_b) == max2 && max == 0)
			max = put_max2(tab, &tab_move, max2);
		else
			max = put_max(tab, &tab_move, max_b, max);
	}
	put_move(&tab_move);
}
