/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:34:36 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:19:14 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_join(t_arg *pf, char *start, int i)
{
	char *temp;

	if (!pf->res)
	{
		pf->res = ft_strnew(i);
		pf->res = ft_strncpy(pf->res, start, i);
		pf->len = pf->len + i;
	}
	else
	{
		temp = pf->res;
		pf->res = ft_strsub(temp, 0, (pf->len + i));
		pf->res = ft_strncat((pf->res + pf->len), start, (size_t)i) - pf->len;
		pf->len = pf->len + i;
		free(temp);
	}
}
