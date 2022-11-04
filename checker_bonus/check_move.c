/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:23:26 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 15:45:25 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_move(t_tab_int *tab, char *str)
{
	if (!ft_strcmp("ra\n", str))
		r_movement_checker(tab, "ra");
	else if (!ft_strcmp("rb\n", str))
		r_movement_checker(tab, "rb");
	else if (!ft_strcmp("rr\n", str))
		r_movement_checker(tab, "rr");
	else if (!ft_strcmp("rrb\n", str))
		rr_movement_checker(tab, "rrb");
	else if (!ft_strcmp("rra\n", str))
		rr_movement_checker(tab, "rra");
	else if (!ft_strcmp("rrr\n", str))
		rr_movement_checker(tab, "rrr");
	else if (!ft_strcmp("sa\n", str))
		s_move_checker(tab, "sa");
	else if (!ft_strcmp("sb\n", str))
		s_move_checker(tab, "sb");
	else if (!ft_strcmp("ss\n", str))
		s_move_checker(tab, "ss");
	else if (!ft_strcmp("pb\n", str))
		p_move_all_checker(tab, "pb");
	else if (!ft_strcmp("pa\n", str))
		p_move_all_checker(tab, "pa");
	else
		return (1);
	return (0);
}
