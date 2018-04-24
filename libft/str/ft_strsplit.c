/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:59:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:26:46 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count++;
	while (s[i] != c && s[i])
		i++;
	while (s[i] == c)
	{
		i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*ft_new_word(char const *str, char c)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(dest = (char*)malloc((sizeof(char)) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**big_tab;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(big_tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words && s[j])
	{
		if (s[j] != c)
			big_tab[i++] = ft_new_word(&s[j++], c);
		while (s[j] != c && s[j])
			j++;
		while (s[j] == c)
			j++;
	}
	big_tab[i] = NULL;
	return (big_tab);
}
