/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:22:23 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/27 14:32:23 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		balisage(t_stock *s, t_room *r)
{
	r->way = s->way;
	return (1);
}

int		ft_recursive(t_stock *s, t_room *r, int cmp)
{
	int		i;

	i = 0;
	if (r->way != 0)
		return (0);
	if (!cmp)
		return (0);
	if (r->special == 2)
		return (balisage(s, r));
	while (r->liaison[i])
	{
		if (ft_recursive(s, r->liaison[i], cmp - 1))
			return (balisage(s, r));
		i++;
	}
	return (0);
}



int		ft_algorithme(t_stock *s)
{
	unsigned int		cmp;
	int					error;

	error = 0;
	cmp = 1;
	s->room_quantity = 8;
	s->way = 1;
	while (cmp <= s->room_quantity)
	{
		if (ft_recursive(s, s->start, cmp))
			s->way += 1;
		s->start->way = 0;
		s->end->way = 0;
		cmp++;
	}
	return (1);
}
