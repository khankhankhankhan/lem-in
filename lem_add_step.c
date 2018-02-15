/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:48:00 by hkang             #+#    #+#             */
/*   Updated: 2018/02/14 14:27:12 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
