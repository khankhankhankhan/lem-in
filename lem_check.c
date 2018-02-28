/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:49:16 by hkang             #+#    #+#             */
/*   Updated: 2018/02/27 17:05:15 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** check if the room is legal
*/

int		ft_room_check(char *line, t_lem *lem)
{
	char **src;

	src = ft_strsplit(line, ' ');
	if (!(src[0] && src[1] && src[2] && !src[3]))
		return (1);
	if (src[1][0] == '-' || src[1][0] == '+')
		check_all_digit(src[1] + 1, lem);
	else
		check_all_digit(src[1], lem);
	if (src[2][0] == '-' || src[2][0] == '+')
		check_all_digit(src[2] + 1, lem);
	else
		check_all_digit(src[2], lem);
	if (lem->error)
	{
		ft_free_doubulechar(src, 3);
		return (1);
	}
	lem_add_room(src, lem);
	return (0);
}

/*
** check if the connect is legal
*/

int		ft_connect_check(char *line, t_lem *lem)
{
	t_room	*room;
	t_room	*room1;
	t_room	*room2;
	char	**src;

	src = ft_strsplit(line, '-');
	if (!src || !src[0] || !src[1])
		return (1);
	room = lem->room;
	room1 = NULL;
	room2 = NULL;
	while (room && (!room1 || !room2))
	{
		if (!ft_strcmp(room->name, src[0]))
			room1 = room;
		else if (!ft_strcmp(room->name, src[1]))
			room2 = room;
		room = room->next;
	}
	if (!room1 || !room2)
		return (0);
	lem_add_connection(room1, room2);
	lem_add_connection(room2, room1);
	return (0);
}

/*
** check if the last_room is in the trace_set's trace
*/

int		check_in_trace(t_room *last_room, t_trace_set *trace_set)
{
	t_trace	*trace;

	trace = trace_set->trace;
	while (trace)
	{
		if (trace->room == last_room)
			return (0);
		trace = trace->next;
	}
	return (1);
}

/*
** check if the last_room is in the step's trace
*/

int		check_in_steps(t_room *last_room, t_trace_set *step)
{
	t_trace	*trace;

	if (step == NULL)
		return (1);
	trace = step->trace;
	while (trace)
	{
		if (trace->room == last_room)
			return (0);
		trace = trace->next;
	}
	return (1);
}

/*
** check if there is an trace can go from start to end
*/

int		check_one_trace(t_lem *lem)
{
	t_trace_set	*t_set;
	t_connect	*connect;

	trace_set_init(lem);
	t_set = lem->trace_set;
	while (t_set)
	{
		connect = t_set->last->room->connect;
		while (connect)
		{
			if (connect->room == lem->end)
			{
				get_trace(t_set, lem);
				free_all_trace_set(lem->trace_set);
				return (1);
			}
			else if (check_in_trace(connect->room, t_set))
				lem->set_last = copy_trace(lem->set_last,
						t_set->trace, connect->room);
			connect = connect->next;
		}
		t_set = t_set->next;
	}
	free_all_trace_set(lem->trace_set);
	return (0);
}
