/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:18:27 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/05 12:05:57 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort_checker(t_tab_int *tab)
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

void	checker(t_tab_int *tab)
{
	char		*line;

	if (check_sort_checker(tab) == -1)
	{
		ft_printf("OK\n");
		ft_free(tab);
		exit(0);
	}
	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_move(tab, line))
		{
			ft_printf("Error\n");
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	if (check_sort_checker(tab) == -1 && tab->length_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	checker(tab_int);
	ft_free(tab_int);
	return (0);
}
