/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_find_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:01:13 by hkang             #+#    #+#             */
/*   Updated: 2018/02/08 11:01:17 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void lem_slove(t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->ant_num)
	{
		lem_find_trace(lem);
		i++;
	}
}

void lem_find_trace(t_lem *lem)
{
	t_trace_set *trace_set;

	trace_set = (t_trace_set*)malloc(sizeof(t_trace_set));
	trace_set->trace = NULL;
	trace_set->next = NULL;
	trace_set->last = NULL;



}

void add_one_trace(t_trace_set *trace_set, t_trace *trace)
{
	if (!trace_set->trace)
	{
		trace_set->trace = trace;
		trace_set->last = trace;
		return ;
	}
	trace_set->last->next = trace;
	trace_set->last = trace;
}

void remove_top_trace(t_trace_set *trace_set)
{
	t_trace_set *tmp;

	tmp = trace_set->trace;

}
