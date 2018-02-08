/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:25 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:33:57 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_octal(va_list *ap, t_arg *pf, char s)
{
	uintmax_t		num;
	unsigned int	len;
	char			*res;

	if (s == 'O')
		pf->l = 1;
	num = getnum_unsig(ap, pf);
	len = ft_getunsig_len(num, 8);
	res = ft_itoa_base((uintmax_t)num, 8, len, '0');
	if (pf->dot == 1 && pf->prec == 0 && num == 0)
		res[0] = 0;
	len = ft_strlen(res);
	if (pf->pound == 1 && !(pf->dot == 0 && num == 0))
		pf->width--;
	if (pf->pound == 1 && pf->prec > (int)len)
		pf->prec--;
	if (pf->zero == 0 && pf->minus == 0)
		repeat_print_width(pf, len, ' ');
	if (!(pf->dot == 0 && num == 0) && pf->pound == 1)
		ft_print_join(pf, "0", 1);
	return (res);
}

void	ft_print_octal(va_list *ap, t_arg *pf, char s)
{
	char	*res;
	int		len;

	res = get_octal(ap, pf, s);
	len = ft_strlen(res);
	if (pf->minus == 1 || pf->zero == 0)
		repeat_print_prec(pf, len, '0');
	if (pf->minus == 0 && pf->zero == 1)
		repeat_print_width(pf, len, '0');
	ft_print_join(pf, res, len);
	repeat_print_width(pf, len, ' ');
	free(res);
}
