/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:06:47 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/19 19:06:41 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		ft_free_struct(t_stock *s)
{
	t_room *tmp;

	tmp = NULL;
	if (s->room)
		tmp = s->room->next;
	while (tmp)
	{
		free(s->room->name);
		free(s->room->liaison);
		free(s->room);
		s->room = tmp;
		tmp = tmp->next;
	}
	free(s->room->name);
	free(s->room->liaison);
	free(s->room);
	free(s->tab);
	free(s);
	return (1);
}
