/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:21:02 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/29 09:30:41 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		ft_test_read(t_stock *s)
{
	t_room		*room;
	int			i;

	ft_printf("ant_nbr %5d\n", s->ant_nbr);
	room = s->room;
	while (room)
	{
		ft_printf("name    %s\n", room->name);
		ft_printf("id      %d\n", room->id);
		ft_printf("ant     %d\n", room->ant);
		ft_printf("special %d\n", room->special);
		ft_printf("way     %d\n", room->way);
		ft_printf("lenght  %d\n", room->lenght);
		ft_printf("x       %d\n", room->x);
		ft_printf("y       %d\n", room->y);
		i = -1;
		while (room->liaison[++i])
			ft_printf("liaison %s\n", room->liaison[i]->name);
		room = room->next;
		ft_putstr("\n\n");
	}
}
