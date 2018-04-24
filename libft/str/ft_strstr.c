/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:35:32 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 17:39:23 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int				i;
	int				j;
	int				save;

	i = 0;
	save = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		j = -1;
		while (haystack[i] == needle[++j])
		{
			if (!needle[j + 1])
				return ((char*)&haystack[save]);
			++i;
		}
		i = ++save;
	}
	return (NULL);
}
