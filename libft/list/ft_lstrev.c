/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 08:12:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:05:55 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/list.h"

void		ft_lstrev(t_list **begin_list)
{
	t_list		*tmp;
	int			cpt;
	int			i;

	cpt = ft_lstsize(*begin_list);
	i = 0;
	while (cpt > 0)
	{
		tmp = *begin_list;
		begin_list = &tmp->next;
		while (i < cpt)
		{
			tmp = tmp->next;
			i++;
		}
		i = 0;
		cpt--;
	}
}
