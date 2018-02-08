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
	char *temp;
	char **split;

	if (ft_strcmp("##start", line) == 0)
	{
		if (get_next_line(0, &temp) <= 0)
		{
				lem->error = 1;
				return ;
		}
		ft_printf("%s\n", temp);
		split = ft_strsplit(temp, ' ');
		lem->error = ft_room_check(split);
		if (lem->error)
			return ;
		lem_add_room(split, lem);
		lem->last->isstart = 1;
		lem->start = lem->last;
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		if (get_next_line(0, &temp) <= 0)
		{
				lem->error = 1;
				return ;
		}
		ft_printf("%s\n", temp);
		split = ft_strsplit(temp, ' ');
		lem->error = ft_room_check(split);
		if (lem->error)
			return ;
		lem_add_room(split, lem);
		lem->last->isend = 1;
		lem->end = lem->last;
	}
	else if (ft_strchr(line, ' '))
	{
		split = ft_strsplit(line, ' ');
		//ft_printf("%s, %s, %s\n", split[0],split[1],split[2]);
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

void lem_read(t_lem *lem)
{
	char *line;

	while (get_next_line(0, &line) != 1)
	lem->ant_num = ft_atoi(line);
	if (lem->ant_num <= 0)
		lem->error = 0;
	//ft_printf("%s\n", line);
	while (get_next_line(0,&line) > 0 && !lem->error)
	{
		ft_printf("%s\n", line);
		get_data_in(line, lem);
		//ft_printf("error = %d\n", lem->error);
	}
}
