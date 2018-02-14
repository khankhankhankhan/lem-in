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
	//lem_step_display(lem);
	int i;
	i = 0;
	//printf("lem_find_trace\n");
  while(1)
  {
		i++;
	//	printf("while lem_find_trace\n");
    last_room = trace_set->last->room;
		//printf("last_room is %s    ", last_room->name);
    connect = last_room->connect;
		step = lem->step;
		if (step)
			step = step->next;
		//printf("connect is %s\n", connect->room->name);
    while(connect)
    {
	//		if (step)
	//			printf("step is %s\n", step->trace->room->name);

		//	lem_step_display(lem);
		//	printf("step is %s\n", step->trace->room->name);
	//		printf("last_room->connect->room is %s\n", last_room->connect->room->name);
			if (connect->room == lem->end)
			{
				display_one_trace(trace_set->trace);
				get_trace(trace_set, lem);
				lem_step_display(lem);
				return ;
			}
			int a;
			int b;

			a = -1;
			b = -1;
			a = check_in_trace(connect->room, trace_set);
	//		ft_printf("a = %d, ", a);
			b = check_in_steps(connect->room, step);
		/*	if (i < 2)
			{
					ft_printf("b = %d, i = %d, index = %d, connect->roomt is %s\n", b, i, lem->index,connect->room->name);
					if (step)
						display_one_trace(step->trace);
					lem_step_display(lem);
				}*/
      //if (check_in_trace(last_room, trace_set) && check_in_steps(last_room, step))
			if (a && b)
			{
				set_last->next = copy_trace(trace_set->trace, connect->room);
				set_last = set_last->next;
					//add_one_trace(trace_set->trace, set_last, connect->room);
					//display_one_trace(set_last->trace);
			}
			connect = connect->next;
		//	while(lem->index > 1);
	//		ft_printf("i\n");
    }
		set_last->next = copy_trace(trace_set->trace, last_room);
		set_last = set_last->next;
		//display_one_trace(set_last->trace);
		t_trace_set *tmp;
		tmp = trace_set;
		trace_set = trace_set->next;
		free_one_trace_set(tmp);
		//add_one_trace(trace_set->trace, set_last, last_room);
		//trace_set = remove_top_trace(trace_set);
  }

}

t_trace_set *remove_top_trace(t_trace_set *trace_set)
{
	t_trace_set *tmp;

	tmp = trace_set;
	trace_set = trace_set->next;
	free_one_trace_set(tmp);
	return (trace_set);
}

t_trace *get_last_trace(t_trace *trace)
{
	t_trace *tmp;

	tmp = trace;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
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
