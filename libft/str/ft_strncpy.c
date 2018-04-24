/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:11:15 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:23:20 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		x;

	x = 0;
	while (src[x] && x < len)
	{
		dst[x] = src[x];
		x++;
	}
	while (x < len)
		dst[x++] = '\0';
	return (dst);
}
