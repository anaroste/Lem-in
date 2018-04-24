/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:01 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:23:22 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/conversion.h"
#include "../header/print.h"
#include "../header/str.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	*str;

	str = ft_itoa(nb);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
}
