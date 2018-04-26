/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:43:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/26 17:21:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	long long		nb;
	int				is_neg;
	int				i;

	nb = 0;
	is_neg = 1;
	i = 0;
	while (str[i] == '\r' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10;
		nb = nb + ((int)str[i] - '0');
		i++;
	}
	return (nb * is_neg);
}
