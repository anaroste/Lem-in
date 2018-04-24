/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:56:12 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:48:07 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/memory.h"
#include "../header/printf.h"
#include "../header/str.h"

static int	ft_print_str(const char *format, int *index)
{
	int		i;

	i = ft_strlen_c(&format[*index], '%');
	write(1, &format[*index], i);
	*index += i;
	return (i);
}

static int	ft_printf_next(char *str, va_list ap, int *count)
{
	int			*info;
	int			(*ft_printf_tab[9])(va_list, int*);

	if (!(info = (int*)malloc(sizeof(int) * 10)))
		return (0);
	ft_printf_tab[0] = &ft_printf_s;
	ft_printf_tab[1] = &ft_printf_di;
	ft_printf_tab[2] = &ft_printf_bouxmx;
	ft_printf_tab[3] = &ft_printf_ms;
	ft_printf_tab[4] = &ft_printf_md;
	ft_printf_tab[5] = &ft_printf_p;
	ft_printf_tab[6] = &ft_printf_momu;
	ft_printf_tab[7] = &ft_printf_c;
	ft_printf_tab[8] = &ft_printf_mc;
	ft_take_infos(str, &info);
	if (info[9] == '%' && ft_last_char_index(str) != 0)
		return (*count += ft_printf_modulo(&info));
	else if (info[9] == 'n')
		return (ft_printf_n(ap, *count));
	else if (info[9] != '%')
		*count += (ft_printf_tab[info[8]])(ap, info);
	ft_memdel((void**)&info);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	char		*str;
	va_list		ap;

	i = 0;
	count = 0;
	str = ft_strdup(format);
	va_start(ap, format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printf_next(&str[i], ap, &count);
			i = i + ft_printf_pass_str(&str[i]);
		}
		else
			count += ft_print_str(str, &i);
	}
	ft_strdel(&str);
	va_end(ap);
	return (count);
}
