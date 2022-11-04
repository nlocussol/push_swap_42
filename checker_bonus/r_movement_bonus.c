/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_movement_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:14 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 15:46:00 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_movement_checker(t_tab_int *tab, char *str)
{
	int	i;
	int	*tab_tmp;

	i = -1;
	if (!ft_strncmp("rra", str, 3) || !ft_strncmp("rrr", str, 3))
	{
		tab_tmp = ft_calloc(tab->length_a, sizeof(int));
		tab_tmp[0] = tab->pile_a[tab->length_a - 1];
		while (i++ < tab->length_a - 2)
			tab_tmp[i + 1] = tab->pile_a[i];
		free(tab->pile_a);
		tab->pile_a = tab_tmp;
	}
	if (!ft_strncmp(str, "rrb", 3) || !ft_strncmp(str, "rrr", 3))
	{
		tab_tmp = ft_calloc(tab->length_b, sizeof(int));
		tab_tmp[0] = tab->pile_b[tab->length_b - 1];
		while (i++ < tab->length_b - 2)
			tab_tmp[i + 1] = tab->pile_b[i];
		free(tab->pile_b);
		tab->pile_b = tab_tmp;
	}
}

void	r_movement_checker(t_tab_int *tab, char *str)
{
	int	i;
	int	*tab_tmp;

	i = -1;
	if (!ft_strncmp(str, "ra", 2) || !ft_strncmp(str, "rr", 2))
	{
		tab_tmp = ft_calloc(tab->length_a, sizeof(int));
		tab_tmp[tab->length_a - 1] = tab->pile_a[0];
		while (i++ < tab->length_a - 2)
			tab_tmp[i] = tab->pile_a[i + 1];
		free(tab->pile_a);
		tab->pile_a = tab_tmp;
	}
	if (!ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2))
	{
		tab_tmp = ft_calloc(tab->length_b, sizeof(int));
		tab_tmp[tab->length_b - 1] = tab->pile_b[0];
		while (i++ < tab->length_b - 2)
			tab_tmp[i] = tab->pile_b[i + 1];
		free(tab->pile_b);
		tab->pile_b = tab_tmp;
	}
}
