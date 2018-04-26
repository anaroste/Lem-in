/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:22:57 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/26 18:56:26 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int	ft_verif_error(char **str)
{
	ft_printf("%s\nerror in the previous line : stop reading\n", *str);
	ft_strdel(str);
	return (0);
}

int			ft_verif_pipe(char **str, t_stock *s)
{
	int		i;
	int		j;
	t_room	*tmp;

	if (**str == '#')
		return (1);
	i = 0;
	tmp = s->room;
	while (tmp)
	{
		if (!ft_strncmp(*str, tmp->name, i = ft_strlen(tmp->name)))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (ft_verif_error(str));
	if ((*str)[i] != '-')
		return (0);
	++i;
	tmp = s->room;
	j = 0;
	while (tmp)
	{
		if (!ft_strncmp(&((*str)[i]), tmp->name, j = ft_strlen(tmp->name)))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (ft_verif_error(str));
	if ((*str)[i + j])
		return (ft_verif_error(str));
	return (1);
}

int			ft_verif_room(char **str)
{
	int		i;

	if (**str == '#')
		return (1);
	i = 0;
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	if (**str == 'L' || !((*str)[i]))
		return (ft_verif_error(str));
	++i;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		++i;
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i] != ' ')
		return (ft_verif_error(str));
	if (!((*str)[i]))
		return (ft_verif_error(str));
	++i;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		++i;
	while (ft_isdigit((*str)[i]))
			++i;
	if ((*str)[i])
		return (ft_verif_error(str));
	return (1);
}

int			ft_verif_ant_nbr(char **str)
{
	int		i;
	i = 0;
	while (ft_isdigit((*str)[i]))
			++i;
	if ((*str)[i] || ft_atoll(*str) > 4294967295)
		return (ft_verif_error(str));
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
			++cpt;
		tmp = tmp->next;
	}
	if (cpt != 1)
		return (0);
	cpt = 0;
	tmp = s->room;
	while (tmp)
	{
		if (tmp->special == 2)
			++cpt;
		tmp = tmp->next;
	}
	if (cpt != 1)
		return (0);
	return (1);
}
