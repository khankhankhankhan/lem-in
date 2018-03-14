/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:50:22 by hkang             #+#    #+#             */
/*   Updated: 2018/03/14 14:33:19 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** check if the room is already exist
** check if the room has the same coodinate with others
*/

int			lem_same_room(char **split, t_lem *lem)
{
	t_room	*t;
	int		x;
	int		y;

	t = lem->room;
	x = ft_atoi(split[1]);
	y = ft_atoi(split[2]);
	while (t)
	{
		if (ft_strcmp(t->name, split[0]) == 0 || (x == t->x && y == t->y))
			return (1);
		t = t->next;
	}
	return (0);
}

/*
**	creat a room
**	copy split[0] to room->name
**	init this room that include start, end, connect and last_connect
**	add the room to the lem
*/

void		lem_add_room(char **split, t_lem *lem)
{
	t_room		*new;

	lem->error = lem_same_room(split, lem);
	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup(split[0]);
	new->next = NULL;
	new->x = ft_atoi(split[1]);
	new->y = ft_atoi(split[2]);
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

int			lem_add_connection(t_room *room1, t_room *room2)
{
	t_connect	*new;

	if (!room1 || !room2)
		return (1);
	new = room1->connect;
	while (new)
	{
		if (new->room == room2)
			return (1);
		new = new->next;
	}
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

/*
** delet the file's last line that non compliant
*/

void		lem_delet_file_tail(t_lem *lem, char *line)
{
	int len;
	int start;

	len = ft_strlen(line) + 1;
	start = ft_strlen(lem->file) - len;
	ft_bzero(lem->file + start, len);
}
