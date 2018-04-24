/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:31:32 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/24 16:20:41 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_room
{
	char			*name
	int				nb;
	int				ant;
	int				x;
	int				y;
	int				on;
	struct s_room	**liaisons;
	struct s_room	*next;
}					t_room;

typedef struct		s_txt
{
	char			*line;
	struct s_txt	*next;
}					t_txt;

typedef struct	s_stock
{
	int			nb_ant;
	t_txt		*txt;
	t_list		*chain;
}				t_stock;
