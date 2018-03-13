/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:48:00 by hkang             #+#    #+#             */
/*   Updated: 2018/03/12 16:14:05 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** check this start and end room's connection is full,
** if its full, return 0;
*/

int		check_step_full(t_trace_set *step, t_room *room)
{
	t_trace		*trace;
	t_connect	*connect;
	int			flag;

	connect = room->connect;
	while (connect)
	{
		trace = step->trace->next;
		flag = 0;
		while (trace)
		{
			if (trace->room == connect->room)
			{
				flag = 1;
				trace = NULL;
			}
			else
				trace = trace->next;
		}
		if (flag == 0)
			return (0);
		connect = connect->next;
	}
	return (1);
}

/*
**  add the trace[index] to the step
**  if the step is end, creat a new step-list
**  this new step-list begin with start room
**  add the new step-list to the step
*/

void	add_step(t_lem *lem)
{
	t_trace_set	*step;
	t_trace		*trace;
	t_trace		*tmp;

	step = lem->step;
	trace = lem->trace[lem->index];
	trace = trace->next;
	while (trace)
	{
		if (!step->next)
		{
			tmp = new_trace(lem->start);
			step->next = new_trace_set(tmp);
		}
		step = step->next;
		if (trace->room != lem->start)
			append_step(step->trace, trace->room);
		trace = trace->next;
	}
	if (check_step_full(step, lem->end) ||
			check_step_full(lem->step_start, lem->start))
		lem->step_start = lem->step_start->next;
}

/*
**  append the room at the last of the trace
*/

void	append_step(t_trace *trace, t_room *room)
{
	t_trace *tmp;

	tmp = trace;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_trace(room);
}
