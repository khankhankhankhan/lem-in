/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:27:29 by hkang             #+#    #+#             */
/*   Updated: 2018/03/14 14:35:19 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** count how many 'c' int the string 'src'
*/

int		ft_count_char(char *src, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			n++;
		i++;
	}
	return (n);
}

/*
** read room from the file
*/

void	lem_get_room(char **line, t_lem *lem)
{
	char *temp;

	temp = NULL;
	while (!check_new_line(line, lem))
	{
		if (ft_strcmp("##start", *line) == 0 || ft_strcmp("##end", *line) == 0)
		{
			get_start_end_room(*line, temp, lem);
			ft_strdel(&temp);
		}
		else if (ft_count_char(*line, ' ') == 2 && (*line)[0] != '#'
				&& (*line)[0] != 'L')
		{
			lem->error = ft_room_check(*line, lem);
			if (lem->error)
				return ;
		}
		else if ((*line)[0] != '#')
		{
			free(temp);
			return ;
		}
		free(*line);
	}
}

/*
** read link from the file
*/

void	lem_get_link(char **line, t_lem *lem)
{
	int flag;

	if (ft_count_char(*line, '-') != 1)
		return ;
	if (ft_connect_check(*line, lem))
		return ;
	ft_strdel(line);
	flag = 0;
	while (!flag && !check_new_line(line, lem))
	{
		if ((*line)[0] != '#' && ft_count_char(*line, '-') == 1)
			flag = ft_connect_check(*line, lem);
		else if ((*line)[0] != '#')
			flag = 1;
		if (!flag)
			free(*line);
		else
			lem_delet_file_tail(lem, *line);
	}
}

/*
** when get the start or en room
*/

void	get_start_end_room(char *line, char *temp, t_lem *lem)
{
	if (check_new_line(&temp, lem))
		return ;
	while (temp[0] == '#')
	{
		ft_strdel(&temp);
		if (check_new_line(&temp, lem))
			return ;
	}
	lem->error = ft_room_check(temp, lem);
	if (lem->error)
		return ;
	if (ft_strcmp("##start", line) == 0 && !lem->start)
	{
		lem->last->isstart = 1;
		lem->start = lem->last;
	}
	else if (ft_strcmp("##end", line) == 0 && !lem->end)
	{
		lem->last->isend = 1;
		lem->end = lem->last;
	}
	else
		lem->error = 1;
	ft_strdel(&temp);
}

/*
** read room and link from the file
*/

void	lem_read(t_lem *lem)
{
	char *line;

	get_number(lem);
	if (lem->error)
		return ;
	lem->trace = (t_trace**)malloc(sizeof(t_trace*) * lem->ant_num);
	lem_get_room(&line, lem);
	if (lem->error)
		return ;
	lem_get_link(&line, lem);
	if (!lem->error)
		ft_strdel(&line);
}
