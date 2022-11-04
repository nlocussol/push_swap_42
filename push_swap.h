/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:37:03 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 15:19:39 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_tab_int
{
	int	*pile_a;
	int	*pile_b;
	int	*cpy;
	int	*index;
	int	length_a;	
	int	length_b;
	int	static_length_a;	
}	t_tab_int;

typedef struct s_list_move
{
	char				*content;
	struct s_list_move	*next;
}	t_list_move;

int			check_move(t_tab_int *tab, char *str);
void		special_sort(t_tab_int *tab, t_list_move **tab_move);
int			check_sort(t_tab_int *tab);
int			check_fastest(t_tab_int *tab, int max2, int max);
int			find_max2(t_tab_int	*tab);
int			find_min_max_index(int *tab, int length, int min_max);
int			nb_chunk(t_tab_int *tab);
int			less_max_chunk(t_tab_int *tab, int len_chunk, int cnt, int len_a);
void		free_str(char *str);
void		put_move(t_list_move **tab_move);
void		free_split(char	**str);
void		add_move(t_list_move **tab_move, char *str);
void		sort_algo(t_tab_int *tab);
void		p_move_all(t_tab_int *tab, t_list_move **tab_move, char *str);
void		s_move(t_tab_int *tab, t_list_move **tab_move, char *str);
void		r_movement(t_tab_int *tab, t_list_move **tab_move, char *str);
void		rr_movement(t_tab_int *tab, t_list_move **tab_move, char *str);
void		ft_free(t_tab_int *tab);
void		ft_initialized_struct(t_tab_int *tab_int, int len_a, int len_b);
int			check_duplicates(t_tab_int *tab);
void		put_to_int(char **tab, t_tab_int *tab_int);
char		*pars_str(char *str, char **argv, int argc);

void		p_move_all_checker(t_tab_int *tab, char *str);
void		s_move_checker(t_tab_int *tab, char *str);
void		r_movement_checker(t_tab_int *tab, char *str);
void		rr_movement_checker(t_tab_int *tab, char *str);

#endif
