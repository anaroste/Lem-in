/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lemin_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:38:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/24 16:39:12 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"
#include "fcntl.h"

int		main(int ac, char **av)
{
	t_stock		*s;
	t_txt		*line;

	if (ac < 2)
	{
		ft_putstr("missing fd                                  connard...\n");
		return (0);
	}
	if (!(s = ft_lemin_read(av[1])))
	{
		ft_putstr("NULL returned : LOOSER\n");
		return (0);
	}
	line = s->begin_txt;
	while (line)
	{
		ft_putstr(line->str);
		ft_putchar('\n');
		line = line->next;
	}
	return (0);
}
