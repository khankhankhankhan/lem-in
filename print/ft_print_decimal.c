/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:10:46 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:20:41 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_int(va_list *ap, t_arg *pf, char s, int *f)
{
	intmax_t		num;
	unsigned int	len;
	char			*res;

	*f = 1;
	if (s == 'D')
		pf->l = 1;
	num = getnum_sig(ap, pf);
	len = ft_getsig_len(num);
	res = ft_strnew(len);
	if (num == 0)
		res[0] = '0';
	if (pf->dot == 1 && pf->prec == 0 && num == 0)
		res[0] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		*f = -1;
	}
	while (num != 0 && len-- > 0)
	{
		res[len] = '0' + num % 10 * (*f);
		num = num / 10;
	}
	return (res);
}

char	*get_int_sig(t_arg *pf, int f)
{
	char *temp;

	temp = ft_strnew(1);
	if (pf->plus == 1 && f == 1)
	{
		temp[0] = '+';
		pf->width--;
	}
	if (f == -1)
	{
		temp[0] = '-';
		pf->width--;
	}
	return (temp);
}

void	ft_print_decimal(va_list *ap, t_arg *pf, char s)
{
	char	*res;
	int		f;
	int		len;

	res = get_int(ap, pf, s, &f);
	len = ft_strlen(res);
	if (pf->space == 1 && pf->plus == 0 && f == 1)
	{
		(pf->res)[pf->len] = ' ';
		pf->len++;
		pf->width--;
	}
	if (pf->minus == 1)
	{
		if (pf->plus == 1 && f == 1)
			repeat_print_width(pf, pf->width - 1, '+');
		repeat_print_prec(pf, len, '0');
		ft_print_join(pf, res, len);
		repeat_print_width(pf, len, ' ');
	}
	else if (pf->minus == 0)
		ft_print_dec_right(res, pf, f);
	free(res);
}

void	ft_print_dec_right(char *res, t_arg *pf, int f)
{
	char	*temp;
	int		len;

	temp = get_int_sig(pf, f);
	if (f == -1)
		res++;
	len = (int)ft_strlen(res);
	if (pf->zero == 1 && pf->prec == 0)
	{
		ft_print_join(pf, temp, ft_strlen(temp));
		if (pf->dot == 0)
			repeat_print_width(pf, len, '0');
		else
			repeat_print_width(pf, len, ' ');
	}
	else if (pf->zero == 0 || pf->prec != 0)
	{
		repeat_print_width(pf, len, ' ');
		ft_print_join(pf, temp, ft_strlen(temp));
	}
	repeat_print_prec(pf, len, '0');
	ft_print_join(pf, res, len);
	free(temp);
}
