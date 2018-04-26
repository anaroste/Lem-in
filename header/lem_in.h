/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:10:33 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/26 17:18:54 by tbleuse          ###   ########.fr       */
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

typedef struct			s_room
{
	char				*name;
	int					id;
	int					ant;
	int					special;
	int					way;
	int					way_nbr;
	int					x;
	int					y;
	struct s_room		**liaison;
	struct s_room		*next;
}						t_room;

typedef struct			s_stock
{
	unsigned int		ant_nbr;
	unsigned int		way;
	unsigned int		room_quantity;
	t_room				*room;
}						t_stock;

/*
**			FONCTIONS
*/

t_stock					*ft_lemin_read(char *file);
int						ft_lemin_pipe_read(t_stock *s, int fd, char **str);
int						ft_algorithme(t_stock *s);
int						ft_verif_pipe(char **str, t_stock *s);
int						ft_verif_room(char **str);
int						ft_verif_ant_nbr(char **str);
int						ft_verif_start_end(t_stock *s);

#endif
