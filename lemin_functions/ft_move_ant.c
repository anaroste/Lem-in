/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:06:44 by tbleuse           #+#    #+#             */
/*   Updated: 2018/07/20 13:17:26 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static void		move_ant(t_room *start, t_room *end, char *name, int c)
{
	if (start->ant > 0)
	{
		end->ant += 1;
		if (c)
			end->ant_name = start->ant_name;
		else
			end->ant_name = start->ant;
		ft_printf("L%u-%s ", end->ant_name, name);
		start->ant -= 1;
		if (c)
			start->ant_name = 0;
	}
}

static void		push_ant(t_stock *s)
{
	t_room		*tmp;
	t_room		*tmp2;
	int			i;

	i = -1;
	while (s->start->liaison[++i])
	{
		if (s->start->liaison[i]->way != 0)
		{
			tmp = s->start->liaison[i];
			while (tmp->ant != 1 && findnext(tmp)->special != 2)
				tmp = findnext(tmp);
			if (tmp->ant == 1)
			{
				while (tmp->ant == 1)
				{
					tmp2 = tmp;
					while (findnext(tmp2)->ant == 1 &&
							findnext(tmp2)->special != 2)
						tmp2 = findnext(tmp2);
					move_ant(tmp2, findnext(tmp2), findnext(tmp2)->name, 1);
				}
			}
		}
	}
}

static void		ft_move_ant_second(t_stock *s, int way)
{
	int		i;

	ft_printf("\n");
	push_ant(s);
	way--;
	if (way < 1)
		way = 1;
	i = -1;
	while (s->start->liaison[++i])
	{
		if (s->start->liaison[i]->way <= way &&
				s->start->liaison[i]->way != 0)
			move_ant(s->start, s->start->liaison[i],
					s->start->liaison[i]->name, 0);
	}
}

int				ft_move_ant(t_stock *s)
{
	int		way;
	int		i;

	i = -1;
	while (s->start->liaison[++i])
		if (s->start->liaison[i]->special == 2)
		{
			while (s->ant_nbr > 0)
				ft_printf("L%i-%s ", s->ant_nbr--, s->end->name);
		}
	s->start->ant = (int)s->ant_nbr;
	way = how_much_way(s) + 1;
	while (s->end->ant != s->ant_nbr)
		ft_move_ant_second(s, way);
	return (1);
}
