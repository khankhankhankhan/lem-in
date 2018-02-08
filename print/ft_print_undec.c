/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:07:39 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:34:53 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_undec(va_list *ap, t_arg *pf, char s)
{
	uintmax_t		num;
	unsigned int	len;
	char			*res;

	if (s == 'U')
		pf->l = 1;
	num = getnum_unsig(ap, pf);
	len = ft_getunsig_len(num, 10);
	res = ft_itoa_base((uintmax_t)num, 10, len, '0');
	if (pf->dot == 1 && pf->prec == 0 && num == 0)
		res[0] = '\0';
	return (res);
}

void	ft_print_undec(va_list *ap, t_arg *pf, char s)
{
	char	*res;
	int		len;

	res = get_undec(ap, pf, s);
	len = (int)ft_strlen(res);
	if (pf->minus == 1)
	{
		repeat_print_prec(pf, len, '0');
		ft_print_join(pf, res, len);
		repeat_print_width(pf, len, ' ');
	}
	if (pf->prec < len)
		pf->prec = len;
	if (pf->minus == 0)
	{
		if (pf->zero == 1)
			repeat_print_width(pf, pf->prec, '0');
		else if (pf->zero == 0)
			repeat_print_width(pf, pf->prec, ' ');
		repeat_print_prec(pf, len, '0');
		ft_print_join(pf, res, len);
	}
	free(res);
}
