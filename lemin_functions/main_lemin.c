/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:25:10 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/26 13:18:41 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			main(int ac, char **av)
{
	t_stock		*s;

	if (ac != 2)
	{
		ft_putstr("Wrong number of arguments\n");
		return (0);
	}
	if (!(s = ft_lemin_read(av[1])) ||
			!ft_find_a_way(s) ||
			!ft_move_ant(s))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_free_struct(s);
	return (0);
}
