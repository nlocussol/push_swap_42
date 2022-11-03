/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:26:49 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/03 18:05:19 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_sort(t_tab_int *tab, t_list_move **tab_move)
{
	int	nb_check;
	int	max_a;

	if (tab->length_a == 2)
	{
		s_move(tab, tab_move, "sa");
		put_move(tab_move);
		ft_free(tab);
		exit(0);
	}
	else
	{
		max_a = find_min_max_index(tab->pile_a, tab->length_a, 1);
		nb_check = tab->pile_a[max_a];
		while (tab->pile_a[0] != nb_check)
			r_movement(tab, tab_move, "ra");
		p_move_all(tab, tab_move, "pb");
		if (check_sort(tab) != -1)
			s_move(tab, tab_move, "sa");
		p_move_all(tab, tab_move, "pa");
		r_movement(tab, tab_move, "ra");
		put_move(tab_move);
		ft_free(tab);
		exit(0);
	}
}
