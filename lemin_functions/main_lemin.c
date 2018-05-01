/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:25:10 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/01 13:55:58 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			main(int ac, char **av)
{
	t_stock		*s;

	if (ac != 1 || !av[0][0])
	{
		ft_putstr("Wrong number of arguments\n");
		return (0);
	}
	if (!(s = ft_lemin_read()))
	{
		ft_putstr("error read\n");
		return (0);
	}
	if (!ft_last_verif(s))
	{
		ft_putstr("invalid file\n");
		return (0);
	}
	if (!ft_algorithme(s))
	{
		ft_putstr("algorithm\n");
		return (0);
	}
	ft_take_info(s);
	ft_test_read(s);
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
	ft_free_struct(s);
	return (0);
}
