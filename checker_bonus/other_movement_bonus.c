/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 17:43:25 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s_move_checker(t_tab_int *tab, char *str)
{
	int	temp;

	if ((!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "ss", 2))
		&& tab->length_a > 1)
	{
		temp = tab->pile_a[0];
		tab->pile_a[0] = tab->pile_a[1];
		tab->pile_a[1] = temp;
	}
	if ((!ft_strncmp(str, "sb", 2) || !ft_strncmp(str, "ss", 2))
		&& tab->length_b > 1)
	{
		temp = tab->pile_b[0];
		tab->pile_b[0] = tab->pile_b[1];
		tab->pile_b[1] = temp;
	}
}

static void	p_move_pa(t_tab_int *tab)
{
	int			*tmp;
	int			*tmp2;
	int			i;

	i = 1;
	tmp = ft_calloc(tab->length_a + 1, sizeof(int));
	tmp2 = ft_calloc(tab->length_b - 1, sizeof(int));
	if (!tmp || !tmp2)
		ft_free(tab);
	tmp[0] = tab->pile_b[0];
	while (i != tab->length_a + 1)
	{
		tmp[i] = tab->pile_a[i - 1];
		i++;
	}
	i = 0;
	while (i != tab->length_b - 1)
	{
		tmp2[i] = tab->pile_b[i + 1];
		i++;
	}
	free(tab->pile_a);
	free(tab->pile_b);
	tab->pile_a = tmp;
	tab->pile_b = tmp2;
}

static void	p_move_pb(t_tab_int *tab)
{
	int			*tmp;
	int			*tmp2;
	int			i;

	i = 1;
	tmp = ft_calloc(tab->length_a - 1, sizeof(int));
	tmp2 = ft_calloc(tab->length_b + 1, sizeof(int));
	if (!tmp || !tmp2)
		ft_free(tab);
	tmp2[0] = tab->pile_a[0];
	while (i != tab->length_b + 1)
	{
		tmp2[i] = tab->pile_b[i - 1];
		i++;
	}
	i = 0;
	while (i != tab->length_a - 1)
	{
		tmp[i] = tab->pile_a[i + 1];
		i++;
	}
	free(tab->pile_a);
	free(tab->pile_b);
	tab->pile_a = tmp;
	tab->pile_b = tmp2;
}

void	p_move_all_checker(t_tab_int *tab, char *str)
{
	if (!ft_strncmp(str, "pa", 2) && tab->length_b != 0)
	{
		p_move_pa(tab);
		tab->length_b--;
		tab->length_a++;
	}
	if (!ft_strncmp(str, "pb", 2) && tab->length_a != 0)
	{
		p_move_pb(tab);
		tab->length_a--;
		tab->length_b++;
	}
}
