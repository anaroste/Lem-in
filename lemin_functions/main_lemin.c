/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:25:10 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/24 17:28:27 by tbleuse          ###   ########.fr       */
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
		return (0);
}
