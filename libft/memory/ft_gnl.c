/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:03:55 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:13:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../header/memory.h"
#include "../header/str.h"

static size_t		ft_strlen_n(const char *str)
{
	size_t				i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int			ft_read_gnl(const int fd, char **str)
{
	char				buf[GNL_BUFF_SIZE + 1];
	char				*tmp;
	int					ret;

	if (*str && ft_strchr(*str, '\n'))
		return (1);
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*str))
		{
			if (!(*str = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buf)))
				return (-1);
			ft_strdel(&tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int					ft_gnl(const int fd, char **line)
{
	static char		*str = NULL;
	char			*tmp;
	int				ret;

	if (fd < 0 || !line || (ret = ft_read_gnl(fd, (&str))) == -1)
		return (-1);
	if (ret == 0 && !(str))
		return (0);
	if (!(*line = ft_strsub(str, 0, ft_strlen_n(str))))
		return (-1);
	tmp = str;
	if (!(str = ft_strsub(tmp, ft_strlen_n(tmp) + 1,
					(ft_strlen(tmp) - ft_strlen_n(tmp)))))
		return (-1);
	ft_strdel(&tmp);
	if (str[0] == '\0')
		ft_strdel(&str);
	return (1);
}
