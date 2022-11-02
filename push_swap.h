/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:37:03 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/01 11:49:41 by nlocusso         ###   ########.fr       */
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
}	t_tab_int;

typedef struct s_list_move
{
	char				*content;
	struct s_list_move	*next;
}	t_list_move;

void		put_move(t_list_move **tab_move);
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

#endif
