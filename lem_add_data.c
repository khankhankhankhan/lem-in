/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:50:22 by hkang             #+#    #+#             */
/*   Updated: 2018/02/14 14:25:46 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	creat a room
**	copy split[0] to room->name
**	init this room that include start, end, connect and last_connect
**	add the room to the lem
*/

void		lem_add_room(char **split, t_lem *lem)
{
	t_room		*new;

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

/*
** creat a new cnnection point, set the new->room is room
*/

t_connect	*new_connect(t_room *room)
{
	t_connect	*new;

	new = (t_connect*)malloc(sizeof(t_connect));
	new->room = room;
	new->next = NULL;
	return (new);
}

/*
**creat a new connect node with room2
**add the new connect node in the last of the room1's connect
*/

int		lem_add_connection(t_room *room1, t_room *room2)
{
	t_connect	*new;

	if (!room1 || !room2)
		return (1);
	new = new_connect(room2);
	if (!room1->last_con)
	{
		room1->connect = new;
		room1->last_con = new;
		return (0);
	}
	room1->last_con->next = new;
	room1->last_con = new;
	return (0);
}
