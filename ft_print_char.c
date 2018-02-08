/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:44:07 by hkang             #+#    #+#             */
/*   Updated: 2017/11/28 20:55:16 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_wch(va_list *ap, t_arg *pf)
{
	wchar_t		num;
	char		*str;
	int			len;

	num = va_arg(*ap, wchar_t);
	str = ft_wchartostr(num);
	len = (int)ft_strlen(str);
	if (len == 0)
		len++;
	if (pf->minus == 0 && pf->zero == 1)
		repeat_print_width(pf, len, '0');
	if (pf->minus == 0 && pf->zero == 0)
		repeat_print_width(pf, len, ' ');
	ft_print_join(pf, str, len);
	if (pf->minus == 1)
		repeat_print_width(pf, len, ' ');
	free(str);
}

void		ft_print_ch(va_list *ap, t_arg *pf, char c)
{
	int num;

	if (pf->l == 1 || c == 'C')
	{
		ft_print_wch(ap, pf);
		return ;
	}
	num = va_arg(*ap, int);
	if (pf->minus == 0)
	{
		if (pf->zero == 1)
			repeat_print_width(pf, 1, '0');
		else
			repeat_print_width(pf, 1, ' ');
	}
	ft_print_join(pf, (char*)&num, 1);
	if (pf->minus == 1)
		repeat_print_width(pf, 1, ' ');
}
