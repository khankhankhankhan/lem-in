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
  t_trace_set *set_last;
  t_room *last_room;
  t_connect *connect;

	trace_set = trace_set_init(lem);
  set_last = trace_set;
  while(1)
  {
    last_room = trace_set->last->room;
    connect = last_room->connect;
    while(connect)
    {
      if (last_room->connnect->room == lem->end)
				return (get_trace(trace_set, lem));
      if (check_in_trace(last_room, trace_set) &&
          check_in_steps(last_room, lem))
					add_one_trace(trace_set->trace, set_last, connect->room);
			connect = connect->next;
    }
		add_one_trace(trace_set->trace, set_last, last_room);
		remove_top_trace(trace_set);
  }

}

void remove_top_trace(t_trace_set *trace_set)
{
	t_trace_set *tmp;

	tmp = trace_set;
	trace_set = trace_set->next;
	free_one_trace_set(tmp);
}

void get_trace(t_trace_set *trace_set, t_lem *lem)
{
	t_trace *copy;
	t_trace *tmp;

	tmp = trace_set->trace;
	lem->trace[lem->index] = new_trace(lem->start);
	copy = lem->trace[lem->index];
	tmp = tmp->next;
	while (tmp)
	{
		copy->next = new_trace(tmp->room);
		copy = copy->next;
		tmp = tmp->next;
	}
	copy->next = new_trace(lem->end);
	free_all_trace_set(trace_set);
	add_step(lem);
}
