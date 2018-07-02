/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:22:23 by anaroste          #+#    #+#             */
/*   Updated: 2018/05/23 14:26:35 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int		ft_recursive(t_stock *s, t_room *r, int cmp)
{
	int		i;

	if (r->way || !cmp)
		return (0);
	if (r->special == 2)
		return (1);
	i = -1;
	while (r->liaison[++i])
		if (ft_recursive(s, r->liaison[i], cmp - 1))
		{
			r->way = s->way;
			return (1);
		}
	return (0);
}

int				ft_algorithme(t_stock *s)
{
	int					cmp;
	int					error;

	error = 0;
	cmp = 1;
	s->room_quantity = 8;
	s->way = 1;
	while (cmp <= s->room_quantity)
	{
		if (s->ant_nbr < s->way)
			return (1);
		if (ft_recursive(s, s->start, cmp))
			s->way += 1;
		s->start->way = 0;
		cmp++;
	}
	return (1);
}
