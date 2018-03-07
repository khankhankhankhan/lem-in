/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_find_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:01:13 by hkang             #+#    #+#             */
/*   Updated: 2018/02/15 15:08:00 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** creat a trace_set and the last_set of this set;
** find the trace and add this trace to lem->trace[index]
*/

void		lem_find_trace(t_lem *lem)
{
	trace_set_init(lem);
	add_one_trace(lem->trace_set, lem->set_last, lem);
	free_all_trace_set(lem->trace_set);
}

/*
** search to the trace until the end ot it
** make sure the step is the same node of trace
*/

t_trace_set	*get_step(t_trace_set *step, t_trace *trace)
{
	t_trace		*tmp;
	t_trace_set	*t_step;

	tmp = trace;
	t_step = step;
	while (tmp)
	{
		if (t_step)
			t_step = t_step->next;
		tmp = tmp->next;
	}
	return (t_step);
}

/*
** got the last of one trace
*/

t_trace		*get_last_trace(t_trace *trace)
{
	t_trace *tmp;

	tmp = trace;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*
** add the trace to the lem[lem-index]
** add the each trace-step to the lem->step
*/

void		get_trace(t_trace_set *trace_set, t_lem *lem)
{
	t_trace		*copy;
	t_trace		*tmp;
	t_trace_set	*step;

	lem->trace[lem->index] = new_trace(lem->start);
	copy = lem->trace[lem->index];
	step = lem->step;
	if (lem->index > 0)
	{
		while (step != lem->step_start)
		{
			step = step->next;
			copy->next = new_trace(lem->start);
			copy = copy->next;
		}
	}
	tmp = trace_set->trace->next;
	while (tmp)
	{
		copy->next = new_trace(tmp->room);
		copy = copy->next;
		tmp = tmp->next;
	}
	add_step(lem);
	copy->next = new_trace(lem->end);
}
