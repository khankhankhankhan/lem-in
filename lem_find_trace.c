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

	lem_step_init(lem);
	i = 0;
	while (i < lem->ant_num)
	{
		ft_printf("slove[%d]\n", i);
		lem_find_trace(lem);
		lem->index++;
		i++;
	}
}

void lem_find_trace(t_lem *lem)
{
	t_trace_set *trace_set;
  t_trace_set *set_last;
	t_trace_set *step;
  t_room *last_room;
  t_connect *connect;

	trace_set = trace_set_init(lem);
  set_last = trace_set;
	step = lem->step;
	printf("lem_find_trace\n");
  while(1)
  {
		printf("while lem_find_trace\n");
    last_room = get_last_room(trace_set->trace);
		printf("last_room is %s\n", last_room->name);
    connect = last_room->connect;
    while(connect)
    {
			printf("step is %s\n", step->trace->room->name);
			if (step)
				step = step->next;
			//printf("step is %s\n", step->trace->room->name);
			printf("last_room->connect->room is %s\n", last_room->connect->room->name);
			if (last_room->connect->room == lem->end)
			{
				get_trace(trace_set, lem);
				return ;
			}
			int a;
			int b;

			a = -1;
			b = -1;
			a = check_in_trace(last_room, trace_set);
			ft_printf("a = %d \n", a);
			b = check_in_steps(last_room, step);

			ft_printf("b = %d\n", b);
      if (check_in_trace(last_room, trace_set) &&
          check_in_steps(last_room, step))
					add_one_trace(trace_set->trace, set_last, connect->room);
			connect = connect->next;
			ft_printf("11111\n");
    }
		display_one_trace(trace_set->trace);
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

t_room *get_last_room(t_trace *trace)
{
	t_trace *tmp;

	tmp = trace;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->room);
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
