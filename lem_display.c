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
		ft_printf("%s,",tmp_connect->name);
		tmp_connect = tmp_connect->next;
	}
	ft_printf("\nlast_con is:%s\n\n", room->last_con->name);
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
