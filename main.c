/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:28:07 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/26 15:41:34 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_move(t_list_move *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->next && ((!ft_strncmp(tmp->content, "ra", 2)
					&& !ft_strncmp(tmp->next->content, "rb", 2))
				|| (!ft_strncmp(tmp->content, "rb", 2)
					&& !ft_strncmp(tmp->next->content, "ra", 2))))
		{
			ft_printf("rr\n");
			tmp = tmp->next;
		}
		else if (tmp->next && ((!ft_strncmp(tmp->content, "rra", 3)
					&& !ft_strncmp(tmp->next->content, "rrb", 3))
				|| (!ft_strncmp(tmp->content, "rrb", 3)
					&& !ft_strncmp(tmp->next->content, "rra", 3))))
		{
			ft_printf("rrr\n");
			tmp = tmp->next;
		}
		else
			ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	put_move(t_list_move **tab_move)
{
	t_list_move	*tmp;

	tmp = *tab_move;
	printf_move(tmp);
	while (*tab_move != NULL)
	{
		tmp = (*tab_move)->next;
		free(*tab_move);
		*tab_move = tmp;
	}
}

int	check_sort(t_tab_int *tab)
{
	int	i;

	i = 0;
	while (i != tab->length_a - 1)
	{
		if (tab->pile_a[i] > tab->pile_a[i + 1])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	char		*str_to_pars;
	char		**tab_str;
	t_tab_int	*tab_int;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str_to_pars = ft_strdup(argv[argc - 1]);
	str_to_pars = pars_str(str_to_pars, argv, argc - 1);
	tab_int = malloc(sizeof(t_tab_int));
	tab_str = ft_split(str_to_pars, ' ');
	free(str_to_pars);
	put_to_int(tab_str, tab_int);
	free_split(tab_str);
	check_duplicates(tab_int);
	sort_algo(tab_int);
	ft_free(tab_int);
	return (0);
}
