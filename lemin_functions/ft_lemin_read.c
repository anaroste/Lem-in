/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:28:27 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/25 16:29:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"
#include <fcntl.h>

static int		ft_add_liaison(t_room *room, t_room *tie_to)
{
	t_room		**tmp;
	int			i;

	i = 1;
	while (room->liaison[i - 1])
		++i;
	tmp = room->liaison;
	if (!(room->liaison = (t_room**)malloc(sizeof(t_room*) * (i + 1))))
		return (0);
	room->liaison[i] = NULL;
	while (--i > 0)
		room->liaison[i] = tmp[i - 1];
	room->liaison[0] = tie_to;
	return (1);
}

static int		ft_lemin_pipe_read(t_stock *s, int fd, char **str)
{
	t_room		*tmp;
	t_room		*tmp2;
	int			i;
	int			ret;

	tmp = s->room;
	tmp2 = s->room;
	if (**str != '#')
	{
		while (ft_strncmp(tmp->name, *str, i = ft_strlen(tmp->name)) && tmp)
			tmp = tmp->next;
		if (!tmp || !((*str)[i]) || !((*str)[i + 1]))
			return (0);
		++i;
		while (ft_strncmp(tmp2->name, &((*str)[i]),
					ft_strlen(tmp2->name)) && tmp2)
			tmp2 = tmp2->next;
		if (!ft_add_liaison(tmp, tmp2) || !ft_add_liaison(tmp2, tmp))
			return (0);
	}
	ft_putendl(*str);
	ft_strdel(str);
	if ((ret = ft_gnl(fd, str)) == 0)
		return (1);
	if (ret == -1)
		return (0);
	return (ft_lemin_pipe_read(s, fd, str));
}

static int		ft_start_pipe(char *str, t_stock *s)
{
	t_room		*tmp;

	tmp = s->room;
	while (tmp)
	{
		if (!ft_strncmp(str, tmp->name, ft_strlen(tmp->name)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_new_room(t_stock *s, char *str)
{
	t_room		*new_room;
	int			i;

	i = 0;
	while (str[i] != ' ' && str[i])
		++i;
	if (!(new_room = (t_room*)malloc(sizeof(t_room))) ||
			!(new_room->liaison = (t_room**)malloc(sizeof(t_room*))) ||
			!(new_room->name = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strncpy(new_room->name, str, i);
	new_room->name[i] = '\0';
	while (str[i] == ' ')
		++i;
	new_room->x = ft_atoi(&str[i]);
	while (str[i] != ' ' && str[i])
		++i;
	new_room->y = ft_atoi(&str[i]);
	new_room->liaison[0] = NULL;
	new_room->ant = 0;
	new_room->special = 0;
	new_room->way = 0;
	new_room->next = s->room;
	s->room = new_room;
	return (1);
}

static int		ft_special_room(t_stock *s, int fd, char **str)
{
	int		start;

	start = 2;
	if ((*str)[2] == 's')
		start = 1;
	ft_putendl(*str);
	ft_strdel(str);
	if (ft_gnl(fd, str) < 1 || !ft_new_room(s, *str))
		return (0);
	s->room->special = start;
	return (1);
}

static int		ft_lemin_room_read(t_stock *s, int fd)
{
	char		*str;
	int			ret;

	if (!(ret = ft_gnl(fd, &str)))
		return (1);
	if (ret == -1)
		return (0);
	if (ft_start_pipe(str, s))
		return (ft_lemin_pipe_read(s, fd, &str));
	if (str[0] != '#')
	{
		if (!ft_new_room(s, str))
			return (0);
	}
	if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		if (!ft_special_room(s, fd, &str))
			return (0);
	ft_putendl(str);
	ft_strdel(&str);
	return (ft_lemin_room_read(s, fd));
}

t_stock			*ft_lemin_read(char *file)
{
	t_stock		*s;
	t_room		*tmp;
	char		*str;
	int			fd;
	int			i;

	if (!(s = (t_stock*)malloc(sizeof(t_stock*))) ||
			!(fd = open(file, O_RDONLY)) ||
			(ft_gnl(fd, &str) < 1))
		return (NULL);
	s->ant_nbr = ft_atoui(str);
	ft_putendl(str);
	ft_strdel(&str);
	s->room = NULL;
	if (!ft_lemin_room_read(s, fd) ||
			(close(fd) == -1))
		return (NULL);
	tmp = s->room;
	i = 0;
	while (tmp)
	{
		tmp->id = ++i;
		tmp = tmp->next;
	}
	return (s);
}
