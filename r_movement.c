/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:14 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/02 18:56:32 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_list_move **lst, t_list_move *new)
{
	t_list_move	*buffer;

	if (!lst)
		return ;
	if (!(*lst))
	{
	*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
}

void	add_move(t_list_move **tab_move, char *str)
{
	t_list_move	*next_move;

	next_move = ft_calloc(1, sizeof(t_list_move));
	if (next_move == NULL)
		exit(0);
	next_move->content = str;
	next_move->next = NULL;
	lstadd_back(tab_move, next_move);
}

void	rr_movement(t_tab_int *tab, t_list_move **tab_move, char *str)
{
	int	i;
	int	*tab_tmp;

	i = -1;
	add_move(tab_move, str);
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

void	r_movement(t_tab_int *tab, t_list_move **tab_move, char *str)
{
	int	i;
	int	*tab_tmp;

	i = -1;
	add_move(tab_move, str);
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
