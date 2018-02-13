/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:22:33 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 13:22:35 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem-in.h"

void ft_free_doubulechar(char **src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(src[i]);
		i++;
	}
	src = NULL;
}

void free_one_trace_set(t_trace_set *trace_set)
{
	t_trace *tmp;
	t_trace *trace;

	trace = trace_set->trace;
	while (trace)
	{
		tmp = trace;
		trace = trace->next;
		free (tmp);
	}
	free (trace_set->last);
}

void free_all_trace_set(t_trace_set *trace_set)
{
	t_trace_set *tmp;

	while(trace_set)
	{
		tmp = trace_set;
		trace_set = trace_set->next;
		free_one_trace_set(tmp);
	}
}
