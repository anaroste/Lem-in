/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:54:38 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:27:05 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/memory.h"

int		*ft_sort_int_tab(int *tab, size_t length)
{
	size_t	index;

	index = 0;
	if (length < 2)
		return (tab);
	while (index < length - 1)
	{
		if (tab[index] > tab[index + 1])
		{
			ft_swap(&tab[index], &tab[index + 1]);
			index = 0;
		}
		++index;
	}
	return (tab);
}
