/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:45:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(dest = (char*)malloc(i + 1)))
		return (NULL);
	dest[i] = '\0';
	while (--i >= 0)
		dest[i] = f(s[i]);
	return (dest);
}
