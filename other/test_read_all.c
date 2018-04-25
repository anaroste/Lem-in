/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:21:02 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/25 16:27:20 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		main(int ac, char **av)
{
	t_stock		*s;
	t_room		*room;
	int			i;

	if (ac < 2)
	{
		ft_putstr("wrong nbr of arg\n");
		return (0);
	}
	if (!(s = ft_lemin_read(av[1])))
	{
		ft_putstr("fail\n");
		return (0);
	}
	ft_printf("ant_nbr %5d\n", s->ant_nbr);
	room = s->room;
	while (room)
	{
		ft_printf("name    %s\n", room->name);
		ft_printf("id      %d\n", room->id);
		ft_printf("ant     %d\n", room->ant);
		ft_printf("special %d\n", room->special);
		ft_printf("way     %d\n", room->way);
		ft_printf("x       %d\n", room->x);
		ft_printf("y       %d\n", room->y);
		i = -1;
		while (room->liaison[++i])
			ft_printf("liaison %s\n", room->liaison[i]->name);
		room = room->next;
		ft_putstr("\n\n");
	}
	return (0);
}
