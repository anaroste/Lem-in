/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:40:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:01:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/conversion.h"

int		ft_conv_utf8(int wbytes, wchar_t wchar, char *s)
{
	if (wbytes == 2)
	{
		s[1] = 0x80 | (wchar & 0x3F);
		s[0] = 0xC0 | (wchar >> 6 & 0x1F);
	}
	else if (wbytes == 3)
	{
		s[2] = 0x80 | (wchar & 0x3F);
		s[1] = 0x80 | (wchar >> 6 & 0x3F);
		s[0] = 0xE0 | (wchar >> 12 & 0x0F);
	}
	else if (wbytes == 4)
	{
		s[3] = 0x80 | (wchar & 0x3F);
		s[2] = 0x80 | (wchar >> 6 & 0x3F);
		s[1] = 0x80 | (wchar >> 12 & 0x3F);
		s[0] = 0xF0 | (wchar >> 18 & 0x07);
	}
	return (wbytes);
}
