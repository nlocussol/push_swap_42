/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:05:44 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/26 12:20:40 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
