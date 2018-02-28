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

/*void get_data_in(char *line, t_lem *lem)
{
	char **split;
	char *temp;

	if (ft_strcmp("##start", line) == 0 || ft_strcmp("##end", line) == 0)
	{
		lem->room = ft_strappend(lem->room, line);
		if (get_next_line(0, &temp) <= 0)
				lem->error = 1;
		while (line[0] == '#')
		{
			lem->room = ft_strappend(lem->room, line);
			get_next_line(0, line);
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
}*/

int  ft_count_char(char *src, char c)
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

void lem_get_room(char **line, t_lem *lem)
{
	char *temp;

	temp = NULL;

	while (!check_new_line(line, lem))
	{
		if (ft_strcmp("##start", *line) == 0 || ft_strcmp("##end", *line) == 0)
		{
			if (check_new_line(&temp, lem))
				return ;
			while (temp[0] == '#')
			{
				if (check_new_line(&temp, lem))
					return ;
			}
			get_start_end_room(*line, temp, lem);
		}
		else if (ft_count_char(*line, ' ') == 2 && (*line)[0] != '#' && (*line)[0] != 'L')
		{
			lem->error = ft_room_check(*line, lem);
			if (lem->error)
				return ;
		}
		else if ((*line)[0] != '#')
			return ;
	}
}

void lem_get_link(char *line, t_lem *lem)
{
	if (ft_count_char(line, '-') != 1)
	{
		lem->error = 1;
		return ;
	}
	lem->error = ft_connect_check(line, lem);
	while (!check_new_line(&line, lem))
	{
		if (line[0] != '#' && ft_count_char(line, '-') == 1)
			lem->error = ft_connect_check(line, lem);
		else if (line[0] != '#')
			lem->error = 1;
	}
}

void get_start_end_room(char *line, char *temp, t_lem *lem)
{

	lem->error = ft_room_check(temp, lem);
	//ft_printf("after get_start_end_room read error is %d\n",lem->error);
	if (lem->error)
		return ;
	if (ft_strcmp("##start", line) == 0 && !lem->start)
	{
		lem->last->isstart = 1;
		lem->start = lem->last;
	}
	else if (ft_strcmp("##end", line) == 0&& !lem->end)
	{
		lem->last->isend = 1;
		lem->end = lem->last;
	}
	else
		lem->error = 1;
}

void ft_appendline(t_lem *lem, char *src)
{
	char *tmp;

	tmp = lem->file;
	lem->file = ft_strjoin(tmp, src);
	free(tmp);
	tmp = lem->file;
	lem->file = ft_strjoin(tmp, "\n");
	free(tmp);
}

int check_new_line(char **line, t_lem *lem)
{
	//ft_printf("check_new_line\n");
	if (lem->error)
		return (1);
	/*int a;
	a = -1;
	a = get_next_line(0, line);
	ft_printf("check_new_line a =  %d\n", a);*/
	if (get_next_line(0, line) <= 0 || ft_strlen(*line) == 0)
	{
		//lem->error = 1;
		//free (line);
		return (1);
	}
	//ft_printf("check_new_line\n");
	//ft_printf("check_new_line new_line is %s\n", line);
	ft_appendline(lem, *line);
	return (0);
}

void check_all_digit(char *src, t_lem *lem)
{
	int i;
//ft_printf("check_all_digit\n");
	i = 0;
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
		{
			lem->error = 1;
			return ;
		}
		i++;
		//ft_printf("i = %d\n", i);
	}
}

void get_number(t_lem *lem)
{
	char *line;

	//ft_printf("get_number\n");
	line = NULL;
	if (check_new_line(&line, lem))
		return ;
	//ft_printf("new_line is %s\n", line);
	//ft_printf("get_number\n");
	while (line[0] == '#')
	{
		//ft_printf("while get_number\n");
		if (check_new_line(&line, lem))
			return ;
	}
	//ft_printf("get_number\n");
  check_all_digit(line, lem);
	//ft_printf("lem-error is %d\n", lem->error);
	if (lem->error)
	{
		free (line);
		return ;
	}
	lem->ant_num = ft_atoi(line);
	if (lem->ant_num <= 0)
	{
		lem->error = 1;
		free (line);
	}
}

void lem_read(t_lem *lem)
{
	char *line;

	line = NULL;
	get_number(lem);
	//ft_printf("num is %d\n", lem->ant_num);
	if (lem->error)
		return ;
	lem_trace_int(lem);
	//ft_printf("num is %d\n", lem->ant_num);
	//ft_printf("num get_number %s\n", lem->file);
	lem_get_room(&line, lem);
	//ft_printf("num lem_get_room %s\n", lem->file);
	if (lem->error)
		return ;
	lem_get_link(line, lem);
	//ft_printf("num lem_get_link %s\n", lem->file);
	/*while (get_next_line(0,&line) > 0 && !lem->error)
	{
		//ft_printf("%s\n", line);
		get_data_in(line, lem);
	}*/
}
