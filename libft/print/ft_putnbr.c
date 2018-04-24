/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:01 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 17:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../header/conversion.h"
#include "../header/print.h"

void	ft_putnbr(int nb)
{
	char	*str;

	if (nb > -1 && nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	if (!(str = ft_itoa(nb)))
		return ;
	ft_putstr(str);
	free(str);
}
