/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:50:22 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 14:50:24 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void lem_add_room(char **split, t_lem *lem)
{
	t_room *new;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup(split[0]);
	new->next = NULL;
	new->isstart = 0;
	new->isend = 0;
	new->connect = NULL;
	new->last_con = NULL;
	ft_free_doubulechar(split, 3);
	if (!lem->last)
	{
		lem->last = new;
		lem->room = new;
		return ;
	}
	lem->last->next = new;
	lem->last = new;
}

t_connect *new_connect(char *src)
{
	t_connect *new;

	new = (t_connect*)malloc(sizeof(t_connect));
	new->name = ft_strdup(src);
	new->next = NULL;
	return (new);
}

void lem_add_connection(t_room *room1, t_room *room2)
{
	t_connect *new;

	new = new_connect(room2->name);
	if (!room1->last_con)
	{
		room1->connect = new;
		room1->last_con = new;
		return ;
	}
	room1->last_con->next = new;
	room1->last_con = new;
}
