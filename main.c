/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:27:12 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 10:27:14 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	main(int ac, char **av)
{
	t_lem *lem;

	lem = NULL;
	if (ac != 1)
		return (lem_display_useage());
	lem = lem_init(lem);
	lem_read(lem);
	if (lem->error)
		return (lem_display_format());
	if (!lem->start || !lem->end)
		return (lem_display_error());
	lem_step_init(lem);
	if (!check_one_trace(lem))
		return (lem_display_error());
	lem->index++;
	while (lem->index < lem->ant_num)
	{
		lem_find_trace(lem);
		lem->index++;
	}
	lem_final_display(lem);
	lem_free_all(lem);
	free(lem);
	av = NULL;
	return (0);
}
