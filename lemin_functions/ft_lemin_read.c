/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:28:27 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/27 15:53:52 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"
#include <fcntl.h>

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
	while (str[i] != ' ')
		++i;
	if (!(new_room = (t_room*)malloc(sizeof(t_room))) ||
			!(new_room->liaison = (t_room**)malloc(sizeof(t_room*))) ||
			!(new_room->name = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strncpy(new_room->name, str, i);
	new_room->name[i++] = '\0';
	new_room->x = ft_atoi(&str[i++]);
	while (ft_isdigit(str[i]))
		++i;
	new_room->y = ft_atoi(&str[++i]);
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
	if (ft_gnl(fd, str) < 1 || !ft_new_room(s, *str) || !ft_verif_room(str))
		return (0);
	s->room->special = start;
	return (1);
}

static int		ft_lemin_room_read(t_stock *s, int fd)
{
	char		*str;
	int			ret;

	if (!(ret = ft_gnl(fd, &str)))
	{
		ft_putendl(str);
		ft_strdel(&str);
		return (1);
	}
	if (ret == -1)
		return (0);
	if (ft_start_pipe(str, s))
		return (ft_lemin_pipe_read(s, fd, &str));
	if (!ft_verif_room(&str))
		return (1);
	if (str[0] != '#')
		if (!ft_new_room(s, str))
			return (0);
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

	if (!(s = (t_stock*)malloc(sizeof(t_stock))) ||
			!(fd = open(file, O_RDONLY)) ||
			(ft_gnl(fd, &str) < 1) ||
			!(ft_verif_ant_nbr(fd, &str)))
		return (NULL);
	s->ant_nbr = ft_atoui(str);
	ft_putendl(str);
	ft_strdel(&str);
	s->room = NULL;
	if (!ft_lemin_room_read(s, fd) || (close(fd) == -1))
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
