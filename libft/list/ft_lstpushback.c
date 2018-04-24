/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 07:29:58 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:05:37 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/list.h"

void		ft_lstpushback(t_list **begin, void *data, size_t size)
{
	t_list		*tmp;

	if (begin)
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(data, size);
	}
}
