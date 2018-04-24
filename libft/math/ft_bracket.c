/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:56:38 by exam              #+#    #+#             */
/*   Updated: 2018/03/21 14:06:36 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_bracket_charcmp(char c1, char c2)
{
	if ((c1 == '(' && c2 == ')') ||
			(c1 == '{' && c2 == '}') ||
			(c1 == '[' && c2 == ']'))
		return (1);
	return (0);
}

int				ft_brackets(char *str)
{
	int		tab[100];
	int		i;

	tab[0] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			tab[++tab[0]] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!ft_bracket_charcmp(tab[tab[0]--], str[i]))
				return (0);
		++i;
	}
	if (tab[0] != 0)
		return (0);
	return (1);
}
