/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:10:33 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/24 17:08:05 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/header/libft.h"

/*
**			STRUCTURES
*/

typedef struct			s_txt
{
	char				*str;
	struct s_txt		*next;
}						t_txt;

typedef struct			s_room
{
	char				*name;
	int					id;
	int					ant;
	int					special;
	int					on;
	int					x;
	int					y;
	struct s_room		**liaison;
	struct s_room		*next;
}

typedef struct			s_stock
{
	int					ant_nbr;
	t_txt				*begin_txt;
	t_room				*room;
}						t_stock;

/*
**			FONCTIONS
*/

#endif
