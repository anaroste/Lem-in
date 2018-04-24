/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:07:01 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 17:49:51 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_char(char const *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while (str[i])
	{
		++i;
		++len;
	}
	--i;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
	{
		--i;
		--len;
	}
	return (len);
}

static char	*ft_strtrim_error(void)
{
	char	*str;

	if (!(str = (char*)malloc(1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strtrim_error());
	len = ft_count_char(s);
	if (len < 0)
		len = 0;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	while (j < len && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
