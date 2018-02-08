/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:25 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:21:45 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex(va_list *ap, t_arg *pf, char s)
{
	uintmax_t		num;
	unsigned int	len;
	char			*res;

	num = getnum_unsig(ap, pf);
	len = ft_getunsig_len(num, 16);
	res = ft_itoa_base((uintmax_t)num, 16, len, s - 23);
	if (pf->dot == 1 && pf->prec == 0 && num == 0)
		res[0] = '\0';
	len = ft_strlen(res);
	if (len != 0 && num == 0)
	{
		ft_print_join(pf, "0", 1);
		return (NULL);
	}
	if (pf->width == 0 && pf->prec == 0 && num == 0 && len == 0)
		return (NULL);
	return (res);
}

void	ft_print_hex_per(char s, t_arg *pf)
{
	ft_print_join(pf, "0", 1);
	ft_print_join(pf, &s, 1);
}

void	ft_print_hex(va_list *ap, t_arg *pf, char s)
{
	char	*res;
	int		len;

	res = get_hex(ap, pf, s);
	if (!res)
		return ;
	len = (int)ft_strlen(res);
	if (pf->pound == 1)
		pf->width = pf->width - 2;
	if (pf->pound == 1 && pf->zero == 0 && pf->minus == 0)
		repeat_print_width(pf, len, ' ');
	if (pf->pound == 1)
		ft_print_hex_per(s, pf);
	if (pf->pound == 0 && pf->zero == 0 && pf->minus == 0)
		repeat_print_width(pf, len, ' ');
	if (pf->zero == 1 && pf->minus == 0)
		repeat_print_width(pf, len, '0');
	if (pf->zero == 0 && pf->minus == 0)
		repeat_print_prec(pf, len, '0');
	ft_print_join(pf, res, len);
	repeat_print_width(pf, len, ' ');
	free(res);
}
