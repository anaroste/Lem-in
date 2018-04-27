/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:22:57 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/27 16:06:25 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			ft_verif_error(char **str)
{
	ft_printf("%s\nerror in the previous line : stop reading\n", *str);
	ft_strdel(str);
	return (0);
}

int			ft_verif_ant_nbr(char **str)
{
	int		i;

	i = 0;
	if (!ft_isdigit(**str) && **str != '+')
		return (ft_verif_error(str));
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i] || ft_atoll(*str) > 4294967295)
		return (ft_verif_error(str));
	return (1);
}

static int	ft_verif_end(t_stock *s)
{
	int		cpt;
	t_room	*tmp;

	cpt = 0;
	tmp = s->room;
	while (tmp)
	{
		if (tmp->special == 2)
		{
			s->end = tmp;
			++cpt;
		}
		tmp = tmp->next;
	}
	if (cpt != 1)
		return (0);
	return (1);
}

int			ft_verif_start_end(t_stock *s)
{
	t_room		*tmp;
	int			cpt;

	cpt = 0;
	tmp = s->room;
	while (tmp)
	{
		if (tmp->special == 1)
		{
			s->start = tmp;
			++cpt;
		}
		tmp = tmp->next;
	}
	if (cpt != 1)
		return (0);
	return (ft_verif_end(s));
}
