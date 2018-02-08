/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:49:16 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 14:49:18 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ft_room_check(char **src)
{
	if (src[1] && src[2] && !src[3])
		return (0);
	return (1);
}

int ft_connect_check(char **src, t_lem *lem)
{
	t_room *room;
	t_room *room1;
	t_room *room2;

	room = lem->room;
	room1 = NULL;
	room2 = NULL;
	while(room && (!room1 || !room2))
	{
		if (!ft_strcmp(room->name, src[0]))
			room1 = room;
		else if (!ft_strcmp(room->name, src[1]))
			room2 = room;
		room = room->next;
	}
	if (!room1 || !room2)
		return (1);
	lem_add_connection(room1, room2);
	lem_add_connection(room2, room1);
	return (0);
}
