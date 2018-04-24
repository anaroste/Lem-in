/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:49:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:23:58 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[size] = '\0';
	return (str);
}
