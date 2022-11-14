/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:26:49 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/11 14:27:28 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2and3(t_tab_int *tab, t_list_move **tab_move)
{
	int	nb_check;
	int	max_a;
	int	min_a;

	if (tab->length_a == 2 && check_sort(tab) != -1)
		s_move(tab, tab_move, "sa");
	else if (tab->length_a == 3)
	{
		max_a = find_min_max_index(tab->pile_a, tab->length_a, 1);
		min_a = find_min_max_index(tab->pile_a, tab->length_a, 0);
		if (max_a == 0 && min_a == 2)
		{
			s_move(tab, tab_move, "sa");
			r_movement(tab, tab_move, "rra");
			return ;
		}
		nb_check = tab->pile_a[max_a];
		while (tab->pile_a[0] != nb_check)
			r_movement(tab, tab_move, "ra");
		p_move_all(tab, tab_move, "pb");
		if (check_sort(tab) != -1)
			s_move(tab, tab_move, "sa");
		p_move_all(tab, tab_move, "pa");
		r_movement(tab, tab_move, "ra");
	}
}

void	sort_4(t_tab_int *tab, t_list_move **tab_move)
{
	int	min_a;
	int	nb_check;

	while (tab->length_a != 2)
	{
		min_a = find_min_max_index(tab->pile_a, tab->length_a, 0);
		nb_check = tab->pile_a[min_a];
		while (tab->pile_a[0] != nb_check)
		{
			if (min_a <= tab->length_a / 2)
				r_movement(tab, tab_move, "ra");
			else
				rr_movement(tab, tab_move, "rra");
		}
		p_move_all(tab, tab_move, "pb");
	}
	sort_2and3(tab, tab_move);
	p_move_all(tab, tab_move, "pa");
	p_move_all(tab, tab_move, "pa");
}

void	sort_5(t_tab_int *tab, t_list_move **tab_move)
{
	int	min_a;
	int	nb_check;

	min_a = find_min_max_index(tab->pile_a, tab->length_a, 0);
	nb_check = tab->pile_a[min_a];
	while (tab->pile_a[0] != nb_check)
	{
		if (min_a <= tab->length_a / 2)
			r_movement(tab, tab_move, "ra");
		else
			rr_movement(tab, tab_move, "rra");
	}
	p_move_all(tab, tab_move, "pb");
	sort_4(tab, tab_move);
	p_move_all(tab, tab_move, "pa");
}

void	special_sort(t_tab_int *tab, t_list_move **tab_move)
{
	if (tab->length_a < 4)
		sort_2and3(tab, tab_move);
	else if (tab->length_a == 4)
		sort_4(tab, tab_move);
	else
		sort_5(tab, tab_move);
	put_move(tab_move);
	ft_free(tab);
	exit(0);
}
