/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:41:34 by exam              #+#    #+#             */
/*   Updated: 2018/03/21 13:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/str.h"

static char	*ft_special_itoa(int base)
{
	if (base == 10)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

static int	ft_itoa_length(int value, int base)
{
	int		count;

	count = 0;
	if (value < 0 && base == 10)
		++count;
	while (value)
	{
		value /= base;
		++count;
	}
	return (count);
}

char		*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*str;
	int		length;

	tab = "0123456789ABCDEF";
	if (value == -2147483648)
		return (ft_special_itoa(base));
	if (base < 2)
		return (NULL);
	if (!value)
		return (ft_strdup("0"));
	length = ft_itoa_length(value, base);
	if (!(str = (char*)malloc(length + 1)))
		return (NULL);
	if (base == 10 && value < 0)
		str[0] = '-';
	if (value < 0)
		value = -value;
	str[length--] = '\0';
	while (value > 0)
	{
		str[length--] = tab[value % base];
		value = value / base;
	}
	return (str);
}
