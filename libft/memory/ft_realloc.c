/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:47:19 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:11:30 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/memory.h"
#include "../header/str.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*ptr2;

	if (!(ptr2 = malloc(size)))
		return (NULL);
	ptr2 = ft_memcpy(ptr2, ptr, ft_strlen((char*)ptr));
	ft_memdel(&ptr);
	return (ptr2);
}
