/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:08:28 by hkang             #+#    #+#             */
/*   Updated: 2018/02/15 15:11:59 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem		*lem_init(t_lem *lem)
{
	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->ant_num = 0;
	lem->trace = NULL;
	lem->room = NULL;
	lem->last = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->index = 0;
	lem->error = 0;
	lem->step = NULL;
	lem->step_start = NULL;
	lem->trace_set = NULL;
	lem->set_last = NULL;
	lem->file = ft_strnew(1);
	return (lem);
}

t_trace_set	*step_init(t_lem *lem)
{
	t_trace_set	*step;
	t_trace		*trace;

	trace = lem->trace[lem->index - 1];
	step = lem->step;
	while (trace->next->room == lem->start)
	{
		trace = trace->next;
		if (trace->next && trace->next->room == lem->start)
			step = step->next;
	}
	return (step);
}

void		trace_set_init(t_lem *lem)
{
	t_trace_set *trace_set;

	trace_set = (t_trace_set*)malloc(sizeof(t_trace_set));
	trace_set->next = NULL;
	trace_set->trace = (t_trace*)malloc(sizeof(t_trace));
	trace_set->trace->room = lem->start;
	trace_set->trace->next = NULL;
	trace_set->last = trace_set->trace;
	lem->trace_set = trace_set;
	lem->set_last = trace_set;
}

void		lem_step_init(t_lem *lem)
{
	lem->step = (t_trace_set*)malloc(sizeof(t_trace_set));
	lem->step->trace = new_trace(lem->start);
	lem->step->last = lem->step->trace;
	lem->step->next = NULL;
	lem->step_start = lem->step;
}
