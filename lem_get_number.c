/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:38:56 by hkang             #+#    #+#             */
/*   Updated: 2018/03/06 11:38:59 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** get how many ants in the box
*/

void	get_number(t_lem *lem)
{
	char *line;

	line = NULL;
	if (check_new_line(&line, lem))
		return ;
	while (line[0] == '#')
	{
		free(line);
		if (check_new_line(&line, lem))
			return ;
	}
	check_all_digit(line, lem);
	if (lem->error)
	{
		free(line);
		return ;
	}
	lem->ant_num = ft_atoi(line);
	if (lem->ant_num <= 0)
		lem->error = 1;
	free(line);
}

/*
** get a new line, then check if it the end of the file
** if not the end, append this line in the end of the lem->file
*/

int		check_new_line(char **line, t_lem *lem)
{
	if (lem->error)
		return (1);
	if (get_next_line(0, line) <= 0 || ft_strlen(*line) == 0)
		return (1);
	ft_appendline(lem, *line);
	return (0);
}

/*
** check if the string 'src' are all digit
*/

void	check_all_digit(char *src, t_lem *lem)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
		{
			lem->error = 1;
			return ;
		}
		i++;
	}
	if (i == 0)
		lem->error = 1;
}

/*
** append new line in the end of lem->file
*/

void	ft_appendline(t_lem *lem, char *src)
{
	char *tmp;

	tmp = lem->file;
	lem->file = ft_strjoin(tmp, src);
	free(tmp);
	tmp = lem->file;
	lem->file = ft_strjoin(tmp, "\n");
	free(tmp);
}
