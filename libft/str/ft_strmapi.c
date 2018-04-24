/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:45:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:21:34 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(dest = (char*)malloc((sizeof(char)) * (i + 1))))
		return (NULL);
	while (s[++j])
		dest[j] = f(j, s[j]);
	dest[j] = '\0';
	return (dest);
}
