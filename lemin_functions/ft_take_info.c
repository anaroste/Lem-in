/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 08:51:49 by anaroste          #+#    #+#             */
/*   Updated: 2018/07/19 11:39:44 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static void		second(t_stock *s, int i, int j)
{
	int		way;
	int		lenght;
	t_room	*tmp;

	while (s->end->liaison[++i])
	{
		tmp = s->end;
		if (tmp->liaison[i]->way != 0)
		{
			lenght = 2;
			way = tmp->liaison[i]->way;
			j = -1;
			tmp = tmp->liaison[i];
			tmp->lenght = lenght++;
			while (tmp->liaison[++j])
				if (tmp->liaison[j]->way == way && tmp->liaison[j]->lenght == 0)
				{
					tmp = tmp->liaison[j];
					tmp->lenght = lenght++;
					j = -1;
				}
				else if (tmp->liaison[j]->special == 1)
					break ;
		}
	}
}

static int		fill_tab(t_stock *s)
{
	int		i;

	i = -1;
	if (!(s->tab = (int *)malloc(sizeof(int) * (s->way + 1))))
		return (0);
	s->tab[0] = s->way - 1;
	while (s->start->liaison[++i] != NULL)
	{
		if (s->start->liaison[i]->way != 0)
			s->tab[s->start->liaison[i]->way] = s->start->liaison[i]->lenght;
	}
	return (1);
}

int				ft_take_info(t_stock *s)
{
	second(s, -1, -1);
	if (!fill_tab(s))
		return (0);
	return (1);
}
