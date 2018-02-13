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

int main(void)
{
	t_lem *lem;

	lem = NULL;
	lem = lem_init(lem);
	lem_read(lem);
	//lem_display(lem);
	ft_printf("ant_num is %d\n",lem->ant_num);
	lem_slove(lem);
	ft_printf("ant_num is %d\n",lem->ant_num);
	lem_trace_display(lem);
	return (0);
}
