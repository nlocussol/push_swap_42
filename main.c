/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:28:07 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/02 23:51:48 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_tab_int *tab)
{
	free(tab->pile_a);
	free(tab->pile_b);
	free(tab->cpy);
	free(tab->index);
	free(tab);
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
	if (!tab->index || !tab->cpy || !tab->pile_b || !tab->pile_a)
		exit(0);
}

void	put_move(t_list_move **tab_move)
{
	t_list_move *tmp;

	tmp = *tab_move;
	while (tmp != NULL)
	{
		if ((!ft_strncmp(tmp->content, "ra", 2)
				&& !ft_strncmp(tmp->next->content, "rb", 2))
			|| (!ft_strncmp(tmp->content, "rb", 2)
				&& !ft_strncmp(tmp->next->content, "ra", 2)))
		{
			ft_printf("rr\n");
			tmp = tmp->next;
		}
		else if ((!ft_strncmp(tmp->content, "rra", 3)
				&& !ft_strncmp(tmp->next->content, "rrb", 3))
			|| (!ft_strncmp(tmp->content, "rrb", 3)
				&& !ft_strncmp(tmp->next->content, "rra", 3)))
		{
			ft_printf("rrr\n");
			tmp = tmp->next;
		}
		else
			ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	while (*tab_move != NULL)
	{
		tmp = (*tab_move)->next;
		free(*tab_move);
		*tab_move = tmp;
	}
}

int	main(int argc, char **argv)
{
	char		*str_to_pars;
	char		**tab_str;
	t_tab_int	*tab_int;
	int			i;
	//char		*tmp;

	i = 0;
	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str_to_pars = ft_strdup(argv[argc - 1]);
	str_to_pars = pars_str(str_to_pars, argv, argc - 1);
	if (str_to_pars == NULL)
	{
		free(str_to_pars);
		write(2, "Error\n", 6);
		return (1);
	}
	tab_int = malloc(sizeof(t_tab_int));
	tab_str = ft_split(str_to_pars, ' ');
	free(str_to_pars);
	put_to_int(tab_str, tab_int);
	while (tab_str[i] != NULL)
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
	check_duplicates(tab_int);
	sort_algo(tab_int);
	/*while (i != tab_int->length_a)
	{
		ft_printf("%d\n", tab_int->pile_a[i]);
		i++;
	}*/
	ft_free(tab_int);
	return (0);
}
