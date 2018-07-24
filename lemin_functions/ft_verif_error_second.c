/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_error_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:37:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/07/24 11:53:51 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int		ft_verif_room_second(char **str, int i)
{
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i] != ' ')
		return (ft_verif_error(str));
	if (!((*str)[i]))
		return (ft_verif_error(str));
	++i;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		++i;
	if (!(ft_isdigit((*str)[i])))
		return (ft_verif_error(str));
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i])
		return (ft_verif_error(str));
	return (1);
}

int				ft_verif_room(char **str)
{
	int		i;

	if (**str == '#')
		return (1);
	i = 0;
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	if (**str == 'L' || !((*str)[i]))
		return (ft_verif_error(str));
	++i;
	if ((*str)[i] == ' ')
		return (ft_verif_error(str));
	if ((*str)[i] == '-' || (*str)[i] == '+')
		++i;
	if (!ft_verif_room_second(str, i))
		return (0);
	return (1);
}
