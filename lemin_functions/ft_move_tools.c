/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:09:06 by anaroste          #+#    #+#             */
/*   Updated: 2018/07/20 16:42:07 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			how_much_way(t_stock *s)
{
	int		place;
	int		way;
	int		i;

	place = 0;
	i = 0;
	way = 0;
	while (++i <= s->tab[0])
	{
		if (place >= s->ant_nbr)
			break ;
		else
		{
			place += s->tab[i];
			way = i;
		}
	}
	return (way);
}

t_room		*findnext(t_room *room)
{
	int		i;

	i = 0;
	while (room->liaison[i] && room->liaison[i]->special != 2)
		i++;
	if (!room->liaison[i])
	{
		i = 0;
		while ((room->liaison[i]->way != room->way) ||
				(room->liaison[i]->lenght != (room->lenght - 1)))
			i++;
	}
	return (room->liaison[i]);
}
