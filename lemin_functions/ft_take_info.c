/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 08:51:49 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/29 09:52:49 by anaroste         ###   ########.fr       */
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
				}
				else if (tmp->liaison[j]->special == 1)
					break ;
		}
	}
}

void			ft_take_info(t_stock *s)
{
	second(s, -1, -1);
}
