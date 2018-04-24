/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:53:58 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <wchar.h>

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, int base);
char		*ft_lltoa(long long n);
char		*ft_ulltoa_base(unsigned long long n, int base);

int			ft_conv_utf8(int wbytes, wchar_t wchar, char *s);
int			ft_wc_convert(char *s, wchar_t wchar);
int			ft_wcs_convert(char *s, wchar_t *pwcs, int n);

#endif
