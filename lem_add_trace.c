/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:06:34 by huakang           #+#    #+#             */
/*   Updated: 2018/02/15 14:31:25 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** copy the trace, add the room in the last of this trace;
** add this trace at the last of the trace_set;
** until the connect room is end, add the trace to the lem by using get_trace
*/

void		add_one_trace(t_trace_set *trace_set,
		t_trace_set *set_last, t_lem *lem)
{
	t_trace_set	*step;
	t_connect	*connect;
	t_room		*last_room;

	while (1)
	{
		last_room = trace_set->last->room;
		connect = last_room->connect;
		step = get_step(lem, trace_set->trace);
		while (connect)
		{
			if (connect->room == lem->end)
			{
				get_trace(trace_set, lem);
				return ;
			}
			else if (check_in_steps(connect->room, step) &&
				check_in_trace(connect->room, trace_set))
				set_last = copy_trace(set_last,
						trace_set->trace, connect->room);
			connect = connect->next;
		}
		set_last = copy_trace(set_last, trace_set->trace, last_room);
		trace_set = trace_set->next;
	}
}

/*
** creat a new trace_set, copy all nodes of trace to this trace_set's trace
** append the room to the end of the trace_set's trace
*/

t_trace_set	*copy_trace(t_trace_set *set_last, t_trace *trace, t_room *room)
{
	t_trace		*tmp;
	t_trace		*copy;
	t_trace		*tmp_copy;
	t_trace_set	*trace_set;

	tmp = trace;
	copy = new_trace(tmp->room);
	tmp_copy = copy;
	tmp = tmp->next;
	while (tmp)
	{
		tmp_copy->next = new_trace(tmp->room);
		tmp_copy = tmp_copy->next;
		tmp = tmp->next;
	}
	tmp_copy->next = new_trace(room);
	trace_set = new_trace_set(copy);
	set_last->next = trace_set;
	return (trace_set);
}

/*
** creat a new trace_set
** init its trace as trace
** set next to NULL
*/

t_trace_set	*new_trace_set(t_trace *trace)
{
	t_trace_set *trace_set;

	trace_set = (t_trace_set*)malloc(sizeof(t_trace_set));
	trace_set->trace = trace;
	trace_set->last = get_last_trace(trace);
	trace_set->next = NULL;
	return (trace_set);
}

/*
** creat a new trace, set room is room, set next to NULL;
*/

t_trace		*new_trace(t_room *room)
{
	t_trace *new;

	new = (t_trace*)malloc(sizeof(t_trace));
	new->room = room;
	new->next = NULL;
	return (new);
}
