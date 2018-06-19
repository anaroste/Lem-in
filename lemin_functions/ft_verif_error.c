/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:22:57 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/23 14:33:28 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			ft_verif_error(char **str)
{
	ft_strdel(str);
	return (0);
}

int			ft_verif_ant_nbr(int fd, char **str)
{
	int		i;

	i = 0;
	while (**str == '#')
	{
		ft_putendl(*str);
		ft_strdel(str);
		if (ft_gnl(fd, str) < 1)
			return (0);
	}
	if (!ft_isdigit(**str) && **str != '+' && ft_strcmp(*str, "-0"))
	{
		ft_putendl(*str);
		return (ft_verif_error(str));
	}
	if (**str == '+' || !ft_strcmp(*str, "-0"))
		++i;
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i] || ft_atoll(*str) > 2147483647)
	{
		ft_putendl(*str);
		return (ft_verif_error(str));
	}
	return (1);
}

static int	ft_verif_double_name(t_stock *s)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = s->room;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (!ft_strcmp(tmp->name, tmp2->name))
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
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
	return (ft_verif_double_name(s));
}

int			ft_last_verif(t_stock *s)
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
