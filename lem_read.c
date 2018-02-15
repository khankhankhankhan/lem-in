/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:27:29 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 10:27:31 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void get_data_in(char *line, t_lem *lem)
{
	char **split;
	char *temp;

	if (ft_strcmp("##start", line) == 0 || ft_strcmp("##end", line) == 0)
	{
		if (get_next_line(0, &temp) <= 0)
		{
				lem->error = 1;
				return ;
		}
		get_start_end_room(line, temp, lem);
	}
	else if (ft_strchr(line, ' '))
	{
		split = ft_strsplit(line, ' ');
		lem->error = ft_room_check(split);
		if (lem->error)
			return ;
		lem_add_room(split, lem);
	}
	else if (ft_strchr(line, '-'))
	{
		split = ft_strsplit(line, '-');
		lem->error = ft_connect_check(split, lem);
	}
}

void get_start_end_room(char *line, char *temp, t_lem *lem)
{
	char **split;
	
	split = ft_strsplit(temp, ' ');
	lem->error = ft_room_check(split);
	if (lem->error)
		return ;
	lem_add_room(split, lem);
	if (ft_strcmp("##start", line) == 0)
	{
		lem->last->isstart = 1;
		lem->start = lem->last;
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		lem->last->isend = 1;
		lem->end = lem->last;
	}
}

void lem_read(t_lem *lem)
{
	char *line;

	get_next_line(0, &line);
	lem->ant_num = ft_atoi(line);
	if (lem->ant_num <= 0)
		lem->error = 0;

	lem_trace_int(lem);
	while (get_next_line(0,&line) > 0 && !lem->error)
	{
		ft_printf("%s\n", line);
		get_data_in(line, lem);
	}
}
