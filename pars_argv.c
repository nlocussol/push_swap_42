/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:08:36 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/03 10:38:08 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_tab_int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->length_a)
	{
		j = 0;
		while (j < tab->length_a)
		{
			if (tab->pile_a[i] == tab->pile_a[j] && j != i)
			{
				write(2, "Error\n", 6);
				ft_free(tab);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	put_to_int(char **tab, t_tab_int *tab_int)
{
	int			i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	ft_initialized_struct(tab_int, i, 0);
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_atoi(tab[i]).check == 1)
		{
			free_split(tab);
			write(2, "Error\n", 6);
			ft_free(tab_int);
		}	
		tab_int->pile_a[i] = ft_atoi(tab[i]).atoi;
		i++;
	}
	ft_memcpy(tab_int->cpy, tab_int->pile_a, tab_int->length_a * sizeof(int));
}

static int	check_minus(char *argv)
{
	int	i;

	i = 0;
	if ((argv[0] == '-' || argv[i] == '+') && !ft_isalnum(argv[i + 1]))
		return (1);
	i++;
	while (argv[i] != '\0')
	{
		if ((argv[i] == '-' || argv[i] == '+') && !ft_whitespace(argv[i - 1])
			&& ft_isalnum(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

static char	*pars_argv(char	*str, char **argv, int argc)
{
	char	*tmp;

	while (argc != 1)
	{
		if (check_minus(argv[argc - 1]) == 1)
			free_str(str);
		tmp = ft_strjoin(" ", str);
		free(str);
		str = tmp;
		tmp = ft_strjoin(argv[argc - 1], str);
		free(str);
		str = tmp;
		argc--;
	}
	return (str);
}

char	*pars_str(char *str, char **argv, int argc)
{
	int		i;

	i = 0;
	if (check_minus(argv[argc]) == 1)
		free_str(str);
	str = pars_argv(str, argv, argc);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			free_str(str);
	}
	return (str);
}
