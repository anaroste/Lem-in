/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:25:10 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/23 15:17:10 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			main(int ac, char **av)
{
	t_stock		*s;

	if (ac != 1 || !av[0][0])
	{
		ft_putstr("./lem-in < [file]\n");
		return (0);
	}
	if (!(s = ft_lemin_read()) ||
			(!ft_last_verif(s)) ||
			(!ft_algorithme(s)) ||
			(!(ft_take_info(s))) ||
			(!ft_verif_way(s)) ||
			(!ft_move_ant(s)))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	write(1, "\n", 1);
	ft_free_struct(s);
	return (0);
}
