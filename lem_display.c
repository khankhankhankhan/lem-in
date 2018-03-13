/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:23:37 by hkang             #+#    #+#             */
/*   Updated: 2018/03/12 13:41:41 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** display the file format
*/

int		lem_display_format(void)
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

int		lem_display_useage(void)
{
	ft_printf("ERROR\n");
	ft_printf("useage: ./lem-in < source_file\n");
	return (0);
}

/*
** display error
*/

int		lem_display_error(void)
{
	ft_printf("ERROR\n");
	return (0);
}

void	lem_display_room(t_trace **trace, int i, int *flag)
{
	t_trace *temp;

	temp = trace[i];
	if (temp->room != temp->next->room)
	{
		if (*flag == 1)
			ft_printf(" ");
		ft_printf("L%d->%s", i + 1, temp->next->room->name);
		*flag = 1;
	}
	trace[i] = trace[i]->next;
	free(temp);
}

void	lem_final_display(t_lem *lem)
{
	int		i;
	int		flag;
	t_trace	**trace;

	flag = 1;
	trace = lem->trace;
	ft_printf("%s\n", lem->file);
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < lem->ant_num)
		{
			if (trace[i]->next)
				lem_display_room(trace, i, &flag);
			i++;
		}
		if (flag)
			ft_printf("\n");
	}
}
