/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:44:15 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:26:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../header/str.h"

int		ft_printnchar(int nb, char c)
{
	char		*str;
	int			nb2;

	if (nb < 1)
		return (0);
	if (!(str = (char*)malloc(nb + 1)))
		return (0);
	nb2 = nb;
	str[nb--] = '\0';
	while (nb >= 0)
		str[nb--] = c;
	write(1, str, nb2);
	ft_strdel(&str);
	return (nb2);
}
