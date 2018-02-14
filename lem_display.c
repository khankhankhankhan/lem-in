/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:23:37 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 16:23:39 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void lem_display_room(t_room *room)
{
	t_connect *tmp_connect;

	tmp_connect = room->connect;
	ft_printf("room name is:%s; start:%d; end:%d;\n", room->name, room->isstart, room->isend);
	ft_printf("connect to:");
	while(tmp_connect)
	{
		ft_printf("%s,",tmp_connect->room->name);
		tmp_connect = tmp_connect->next;
	}
	ft_printf("\nlast_con is:%s\n\n", room->last_con->room->name);
}

void lem_display(t_lem *lem)
{
	t_room *tmp_room;

	tmp_room = lem->room;
	while (tmp_room)
	{
		lem_display_room(tmp_room);
		tmp_room = tmp_room->next;
	}
	ft_printf("last ");
	lem_display_room(lem->last);
	ft_printf("start ");
	lem_display_room(lem->start);
	ft_printf("end ");
	lem_display_room(lem->end);
}

void lem_trace_display(t_lem *lem)
{
	int i;

	i = 0;
	while(i < lem->ant_num)
	{
		ft_printf("num is:%d-----:", i);
		display_one_trace(lem->trace[i]);
		i++;
	}
}

void lem_step_display(t_lem *lem)
{
	t_trace_set *step;
	int i;

	i = 0;
	step = lem->step;
	while(step)
	{
		ft_printf("step is:%d-----:", i);
		display_one_trace(step->trace);
		i++;
		step = step->next;
	}
}
void display_one_trace(t_trace *trace)
{
	t_trace *tmp;
	tmp = trace;
	while (tmp)
	{
		ft_printf("%s->",tmp->room->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void lem_final_display(t_lem *lem)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	t_trace **trace;
	trace = lem->trace;
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < lem->ant_num)
		{
			if (trace[i]->next)
			{
				flag = 1;
				if (trace[i]->room != trace[i]->next->room)
					ft_printf("L%d->%s,", i + 1, trace[i]->next->room->name);
				trace[i]= trace[i]->next;
			}
			i++;
		}
		ft_printf("\n");
	}
}
