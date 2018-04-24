/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:56:22 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/str.h"

static int	ft_int_lenght(int nb)
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

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_int_lenght(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
