/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_read_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:28:27 by tbleuse           #+#    #+#             */
/*   Updated: 2018/06/18 13:02:47 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int		ft_add_liaison(t_room *room, t_room *tie_to)
{
	t_room		**tmp;
	int			i;

	i = 1;
	while (room->liaison[i - 1])
	{
		if (room->liaison[i - 1] == tie_to)
			return (1);
		++i;
	}
	tmp = room->liaison;
	if (!(room->liaison = (t_room**)malloc(sizeof(t_room*) * (i + 1))))
		return (0);
	room->liaison[i] = NULL;
	while (--i > 0)
		room->liaison[i] = tmp[i - 1];
	room->liaison[0] = tie_to;
	free(tmp);
	return (1);
}

static int		ft_fuck_the_norm(char **str, t_room *tmp, t_room *tmp2)
{
	if (!tmp)
		return (ft_verif_error(str));
	if (!ft_add_liaison(tmp, tmp2) || !ft_add_liaison(tmp2, tmp))
		return (0);
	return (1);
}

static int		ft_lemin_pipe_read_two(t_stock *s, int fd, char **str)
{
	int		ret;

	ft_putendl(*str);
	ft_strdel(str);
	if ((ret = ft_gnl(fd, str)) == 0)
		return (1);
	if (ret == -1)
		return (0);
	return (ft_lemin_pipe_read(s, fd, str));
}

int				ft_lemin_pipe_read(t_stock *s, int fd, char **str)
{
	t_room		*tmp;
	t_room		*tmp2;
	int			i;
	int			j;

	tmp = s->room;
	if (**str == '#')
		return (ft_lemin_pipe_read_two(s, fd, str));
	while (tmp)
	{
		tmp2 = s->room;
		j = 0;
		if (!ft_strncmp(tmp->name, *str, i = ft_strlen(tmp->name))
				&& (*str)[i++] == '-')
			while (tmp2 && (ft_strncmp(tmp2->name, &((*str)[i]),
							j = ft_strlen(tmp2->name)) || (*str)[i + j]))
				tmp2 = tmp2->next;
		if (tmp2 && j && !ft_strncmp(tmp2->name, &((*str)[i]),
					j = ft_strlen(tmp2->name) && !(*str)[i + j]))
			break ;
		tmp = tmp->next;
	}
	if (!ft_fuck_the_norm(str, tmp, tmp2))
		return (0);
	return (ft_lemin_pipe_read_two(s, fd, str));
}
