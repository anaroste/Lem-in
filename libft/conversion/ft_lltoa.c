/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:58:35 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "../header/str.h"

static int	ft_nb_lenght(long long nb)
{
	int		lenght;

	lenght = 0;
	if (nb <= 0)
		lenght = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		lenght++;
	}
	return (lenght);
}

char		*ft_lltoa(long long n)
{
	char	*str;
	int		i;

	i = ft_nb_lenght(n);
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
