/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:04:05 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/25 15:00:37 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_atoui(const char *str)
{
	long int	nb;
	long int	i;

	nb = 0;
	i = 0;
	while (str[i] == '\r' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10;
		nb = nb + ((unsigned int)str[i++] - '0');
	}
	return (nb);
}
