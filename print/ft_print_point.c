/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:42:35 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:34:39 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_point(va_list *ap, t_arg *pf)
{
	unsigned long long int	add;
	char					*res;
	int						len;

	add = va_arg(*ap, unsigned long long int);
	res = ft_llitoa_base(add, 16);
	if (add == 0 && pf->dot == 1 && pf->prec == 0)
		res[0] = '\0';
	len = ft_strlen(res);
	pf->width = pf->width - 2;
	if (pf->minus == 0 && pf->zero == 0)
		repeat_print_width(pf, len, ' ');
	ft_print_join(pf, "0x", 2);
	if (pf->minus == 0 && pf->zero == 1)
		repeat_print_width(pf, len, '0');
	else if ((pf->minus == 0 && pf->zero == 0) || pf->minus == 1)
		repeat_print_prec(pf, len, '0');
	ft_print_join(pf, res, len);
	repeat_print_width(pf, len, ' ');
	free(res);
}

int		get_float_bit(long double num, long double limit)
{
	long double	temp;
	int			i;

	temp = num / limit;
	i = 1;
	while (i < 10)
	{
		if (temp < i)
			return (i - 1);
		i++;
	}
	return (9);
}
