/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_error_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:37:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/27 10:41:35 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int		ft_verif_pipe_second(char **str, t_stock *s, int i)
{
	t_room	*tmp;
	int		j;

	tmp = s->room;
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

int				ft_verif_pipe(char **str, t_stock *s)
{
	int		i;
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
	if (!ft_verif_pipe_second(str, s, i))
		return (0);
	return (1);
}

static int		ft_verif_room_second(char **str, int i)
{
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i] != ' ')
		return (ft_verif_error(str));
	if (!((*str)[i]))
		return (ft_verif_error(str));
	++i;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		++i;
	if (!(ft_isdigit((*str)[i])))
		return (ft_verif_error(str));
	while (ft_isdigit((*str)[i]))
		++i;
	if ((*str)[i])
		return (ft_verif_error(str));
	return (1);
}

int				ft_verif_room(char **str)
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
	if (!ft_verif_room_second(str, i))
		return (0);
	return (1);
}
