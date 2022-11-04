/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:22:51 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 11:33:56 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(0);
}

void	free_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(t_tab_int *tab)
{
	free(tab->pile_a);
	free(tab->pile_b);
	free(tab->cpy);
	free(tab->index);
	free(tab);
	exit(0);
}

void	ft_initialized_struct(t_tab_int *tab, int len_a, int len_b)
{
	(void)tab;
	tab->length_a = len_a;
	tab->length_b = len_b;
	tab->pile_a = ft_calloc(len_a, sizeof(int));
	tab->pile_b = ft_calloc(len_b, sizeof(int));
	tab->cpy = ft_calloc(len_a, sizeof(int));
	tab->index = ft_calloc(len_a, sizeof(int));
	tab->static_length_a = len_a;
	if (!tab->index || !tab->cpy || !tab->pile_b || !tab->pile_a)
		exit(0);
}
