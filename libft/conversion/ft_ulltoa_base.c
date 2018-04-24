/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:59:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/str.h"

static int		ft_set_tab(char **tab)
{
	if (!(*tab = (char*)malloc(17)))
		return (0);
	(*tab)[0] = '0';
	(*tab)[1] = '1';
	(*tab)[2] = '2';
	(*tab)[3] = '3';
	(*tab)[4] = '4';
	(*tab)[5] = '5';
	(*tab)[6] = '6';
	(*tab)[7] = '7';
	(*tab)[8] = '8';
	(*tab)[9] = '9';
	(*tab)[10] = 'a';
	(*tab)[11] = 'b';
	(*tab)[12] = 'c';
	(*tab)[13] = 'd';
	(*tab)[14] = 'e';
	(*tab)[15] = 'f';
	(*tab)[16] = '\0';
	return (1);
}

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	int						i;
	unsigned long long		n2;
	char					*tab;
	char					*str;

	i = 0;
	n2 = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n2 > 0)
	{
		n2 = n2 / base;
		i++;
	}
	if (!ft_set_tab(&tab) || !(str = (char*)malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = tab[(n % base)];
		n = n / base;
	}
	ft_strdel(&tab);
	return (str);
}
