/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:08:28 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 16:08:30 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_lem *lem_init(t_lem *lem)
{
	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->ant_num = 0;
	lem->trace = NULL;
	lem->room = NULL;
	lem->last = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->ant = NULL;
	lem->index = 0;
	lem->error = 0;
	lem->step = NULL;
	return (lem);
}

t_trace_set *trace_set_init(t_lem *lem)
{
  t_trace_set *trace_set;

  trace_set = (t_trace_set*)malloc(sizeof(t_trace_set));
  trace_set->next = NULL;
  trace_set->trace = (t_trace*)malloc(sizeof(t_trace));
  trace_set->trace->room = lem->start;
  trace_set->trace->next = NULL;
	trace_set->last = trace_set->trace;
  return (trace_set);
}

void lem_trace_int(t_lem *lem)
{
	int i;

	i = 0;
	lem->trace = (t_trace**)malloc(sizeof(t_trace*) * lem->ant_num);
	while (i < lem->ant_num)
	{
		lem->trace[i] = new_trace(lem->start);
		i++;
	}
}

void lem_step_init(t_lem *lem)
{
	lem->step = (t_trace_set*)malloc(sizeof(t_trace_set));
	lem->step->trace = new_trace(lem->start);
	lem->step->last = lem->step->trace;
	lem->step->next = NULL;
}
