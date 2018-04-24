/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:24:20 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:22:18 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/str.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int					i;
	size_t				j;

	i = ft_strlen(s1);
	j = 0;
	if (n > 0)
	{
		while (j < n && s2[j])
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	return (s1);
}
