/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:10:33 by anaroste          #+#    #+#             */
/*   Updated: 2018/05/23 14:28:47 by anaroste         ###   ########.fr       */
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
	int					ant_name;
	int					special;
	int					way;
	int					lenght;
	int					x;
	int					y;
	struct s_room		**liaison;
	struct s_room		*next;
}						t_room;

typedef struct			s_stock
{
	int					ant_nbr;
	int					way;
	int					room_quantity;
	int					*tab;
	t_room				*start;
	t_room				*end;
	t_room				*room;
}						t_stock;

/*
**			FONCTIONS
*/

t_stock					*ft_lemin_read(void);
int						ft_lemin_pipe_read(t_stock *s, int fd, char **str);
int						ft_algorithme(t_stock *s);
int						ft_verif_pipe(char **str, t_stock *s);
int						ft_verif_room(char **str);
int						ft_verif_ant_nbr(int fd, char **str);
int						ft_verif_error(char **str);
int						ft_last_verif(t_stock *s);
int						ft_free_struct(t_stock *s);
int						ft_move_ant(t_stock *s);
int						ft_verif_way(t_stock *s);
void					ft_test_read(t_stock *s);
int						ft_take_info(t_stock *s);
int						how_much_way(t_stock *s);
t_room					*findnext(t_room *room);

#endif
