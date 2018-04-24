/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:32:33 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:09:49 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	const unsigned char		*tmp;
	unsigned char			*tmp2;

	i = 0;
	tmp = src;
	tmp2 = dst;
	while (i < n && tmp[i] != (unsigned char)c)
	{
		tmp2[i] = tmp[i];
		i++;
	}
	if (i < n && tmp[i] == (unsigned char)c)
	{
		tmp2[i] = tmp[i];
		return (&dst[i + 1]);
	}
	return (NULL);
}
