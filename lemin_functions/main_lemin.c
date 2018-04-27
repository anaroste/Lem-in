/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:25:10 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/27 16:06:20 by tbleuse          ###   ########.fr       */
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
	if (!(s = ft_lemin_read(av[1])))
	{
		ft_putstr("error read\n");
		return (0);
	}
	if (!ft_verif_start_end(s))
	{
		ft_putstr("wrong number of start/end\n");
		return (0);
	}
	if (!ft_algorithme(s))
	{
		ft_putstr("algorithm\n");
		return (0);
	}
	if (!ft_verif_way(s))
	{
		ft_putstr("no way\n");
		return (0);
	}
	if (!ft_move_ant(s))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_test_read(s);
	ft_free_struct(s);
	return (0);
}
