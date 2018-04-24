/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:28:27 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/24 16:39:52 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"
#include "fcntl.h"

static int		ft_lemin_recursive_read(t_txt *previous_line, int fd)
{
	char		*line;
	int			ret;

	if (!(ret = ft_gnl(fd, &line)))
	{
		previous_line->next = NULL;
		return (1);
	}
	if (ret == -1 ||
			!(previous_line->next = (t_txt*)malloc(sizeof(t_txt*))))
		return (0);
	previous_line = previous_line->next;
	previous_line->str = line;
	return (ft_lemin_recursive_read(previous_line, fd));
}

t_stock			*ft_lemin_read(char *file)
{
	t_stock		*s;
	t_txt		*line;
	int			fd;

	if (!(s = (t_stock*)malloc(sizeof(t_stock*))) ||
			!(line = (t_txt*)malloc(sizeof(t_txt*))) ||
			!(fd = open(file, O_RDONLY)) ||
			(ft_gnl(fd, &line->str) == -1))
		return (NULL);
	s->begin_txt = line;
	if (!(ft_lemin_recursive_read(line, fd)) ||
			(close(fd) == -1))
		return (NULL);
	return (s);
}
