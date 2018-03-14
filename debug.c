/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:29:30 by hkang             #+#    #+#             */
/*   Updated: 2018/03/14 14:24:56 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_one_trace(t_trace *trace)
{
	t_trace *t;

	t = trace;
	while (t)
	{
		ft_printf("%s->", t->room->name);
		t = t->next;
	}
}

void	display_one_trace_set(t_trace_set *trace_set)
{
	t_trace_set *t;

	t = trace_set;
	while (t)
	{
		display_one_trace(t->trace);
		ft_printf("\n");
		t = t->next;
	}
}
