/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:08:28 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 16:08:30 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_lem *lem_init(t_lem *lem)
{
	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->ant_num = 0;
	lem->step = 0;
	lem->room = NULL;
	lem->last = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->ant = NULL;
	lem->error = 0;
	return (lem);
}
