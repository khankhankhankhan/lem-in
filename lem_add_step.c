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
	t_trace *step;
	t_trace *trace;

	step = lem->step;
	trace = lem->trace[lem->index];
	while(trace)
	{
		if (step->room != lem->start)
		{
			append_trace(step->room);
		}
		trace = trace->next;
	}
}
