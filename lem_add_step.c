/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:48:00 by hkang             #+#    #+#             */
/*   Updated: 2018/02/09 14:48:03 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void add_step(t_lem *lem)
{
	t_trace_set *step;
	t_trace *trace;
	t_trace *tmp;
	step = lem->step;
	trace = lem->trace[lem->index];
	trace = trace->next;
	while(trace)
	{
		if (!step->next)
		{
			tmp = new_trace(lem->start);
			step->next = new_trace_set(tmp);
		}
		step = step->next;
		if (trace->room != lem->start)
			append_step(step->trace, trace->room);
		/*{
			step->last->next = new_trace(trace->room);
			step->last = step->last->next;
		}*/
		trace = trace->next;
	}
}

void append_step(t_trace *trace, t_room *room)
{
	t_trace *tmp;

	tmp = trace;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_trace(room);
}
