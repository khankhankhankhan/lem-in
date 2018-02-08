/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:01:04 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:33:19 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_end(char *res, unsigned int i)
{
	i--;
	if (res[i] < '5')
	{
		res[i] = '\0';
		return (res);
	}
	res[i] = '\0';
	i--;
	while (i > 0)
	{
		if (res[i] == '.')
			i--;
		if (res[i] == '9')
			res[i] = '0';
		else
		{
			res[i] = res[i] + 1;
			return (res);
		}
		i--;
	}
	return (res);
}

void	float_init(long double num, unsigned int *i, int *f, char *res)
{
	*i = 0;
	if (num < 0.0)
	{
		*f = -1;
		res[0] = '-';
		(*i)++;
	}
}

char	*ft_floattostr(long double num, t_arg *pf, int *f)
{
	unsigned int	i;
	int				t;
	long double		limit;
	unsigned int	len;
	char			*res;

	len = ft_getdouble_len(num, &limit);
	res = ft_strnew(len + (unsigned int)pf->prec + 1);
	float_init(num, &i, f, res);
	res[len - 1] = '.';
	while (i < len + (unsigned int)pf->prec + 1)
	{
		if (i == len - 1)
			i++;
		t = get_float_bit((*f) * num, limit);
		res[i] = t + '0';
		num = num - (*f) * limit * t;
		limit = limit / 10;
		i++;
	}
	res = float_end(res, i);
	return (res);
}

char	*get_float(va_list *ap, t_arg *pf, int *f)
{
	long double		num;
	char			*res;

	if (pf->l == 1)
		num = va_arg(*ap, long double);
	else
		num = (long double)va_arg(*ap, double);
	if (pf->prec == 0)
		pf->prec = 6;
	res = ft_floattostr(num, pf, f);
	return (res);
}

void	ft_print_float(va_list *ap, t_arg *pf)
{
	char	*res;
	int		f;
	int		len;

	f = 1;
	res = get_float(ap, pf, &f);
	len = (int)ft_strlen(res);
	if (pf->space == 1 && pf->plus == 0 && f == 1)
	{
		ft_print_join(pf, " ", 1);
		pf->width--;
	}
	if (pf->minus == 1)
	{
		if (pf->plus == 1 && f == 1)
			repeat_print_width(pf, pf->width - 1, '+');
		repeat_print_prec(pf, len, '0');
		write(1, res, len);
		repeat_print_width(pf, len, ' ');
	}
	else if (pf->minus == 0)
		ft_print_dec_right(res, pf, f);
	free(res);
}
