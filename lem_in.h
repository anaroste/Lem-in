/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:10:33 by anaroste          #+#    #+#             */
/*   Updated: 2018/04/24 15:28:28 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/header/libft.h"

/*
**			STRUCTURES
*/

typedef struct			s_txt
{
	char				*str;
	struct stxt			*next;
}						t_txt;

typedef struct			s_stock
{
	int					ant_nbr;
	t_txt				*begin_txt;
}						t_stock;

/*
**			FONCTIONS
*/

#endif
