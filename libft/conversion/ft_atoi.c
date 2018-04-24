/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:43:25 by tbleuse           #+#    #+#             */
/*   Updated: 2017/11/17 14:47:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long int		nb;
	long int		is_neg;
	long int		i;

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
