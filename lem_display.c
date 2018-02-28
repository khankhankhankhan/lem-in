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

/*
** display the file format
*/

int lem_display_format(void)
{
	ft_printf("ERROR\n");
	ft_printf("check your format like this:\n");
	ft_printf("number_of_ants : integer number more than 0\n");
	ft_printf("the_rooms : name coord_x coord_y\n");
	ft_printf("connect : name1-name2\n");
	ft_printf("broken by comments, which start with #\n");
	return (0);
}

/*
** display the useage
*/

int lem_display_useage(void)
{
	ft_printf("ERROR\n");
	ft_printf("useage: ./lem-in < source_file\n");
	return (0);
}

/*
** display error
*/

int lem_display_error(void)
{
	ft_printf("ERROR\n");
	return (0);
}

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
	t_trace **trace;

	flag = 1;
	trace = lem->trace;
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < lem->ant_num)
		{
			if (trace[i]->next)
			{
				if (trace[i]->room != trace[i]->next->room)
				{
					if (flag == 1)
						ft_printf(" ");
					ft_printf("L%d->%s", i + 1, trace[i]->next->room->name);
					flag = 1;
				}
				trace[i]= trace[i]->next;
			}
			i++;
		}
		ft_printf("\n");
	}
}
