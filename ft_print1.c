/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:08:36 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:41:00 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	getnum_sig(va_list *ap, t_arg *pf)
{
	intmax_t	n;

	if (pf->ll == 1)
		n = va_arg(*ap, long long int);
	else if (pf->l == 1)
		n = va_arg(*ap, long int);
	else if (pf->j == 1)
		n = va_arg(*ap, intmax_t);
	else if (pf->z == 1)
		n = va_arg(*ap, ssize_t);
	else if (pf->hh == 1)
	{
		n = va_arg(*ap, int);
		n = (char)n;
	}
	else if (pf->h == 1)
	{
		n = va_arg(*ap, int);
		n = (short)n;
	}
	else
		n = va_arg(*ap, int);
	return (n);
}

uintmax_t	getnum_unsig(va_list *ap, t_arg *pf)
{
	uintmax_t	n;

	if (pf->ll == 1)
		n = va_arg(*ap, unsigned long long int);
	else if (pf->l == 1)
		n = va_arg(*ap, unsigned long int);
	else if (pf->j == 1)
		n = va_arg(*ap, uintmax_t);
	else if (pf->z == 1)
		n = va_arg(*ap, size_t);
	else if (pf->hh == 1)
	{
		n = va_arg(*ap, unsigned int);
		n = (unsigned char)n;
	}
	else if (pf->h == 1)
	{
		n = va_arg(*ap, unsigned int);
		n = (unsigned short)n;
	}
	else
		n = va_arg(*ap, unsigned int);
	return (n);
}

void		ft_print_nosignal(t_arg *pf, const char *format)
{
	if (!(*format))
		return ;
	if (pf->minus == 1)
	{
		ft_print_join(pf, (char*)format, 1);
		pf->width--;
		repeat_print_width(pf, 0, ' ');
	}
	else if (pf->minus == 0)
	{
		if (pf->zero == 1)
			repeat_print_width(pf, 1, '0');
		else if (pf->zero == 0)
			repeat_print_width(pf, 1, ' ');
		ft_print_join(pf, (char*)format, 1);
	}
}

void		repeat_print_width(t_arg *pf, int std, char c)
{
	int		l;
	char	*temp;

	if (std < pf->prec)
		std = pf->prec;
	l = pf->width - std;
	if (l <= 0)
		return ;
	pf->width = pf->width - l;
	if (!pf->res)
		pf->res = ft_strnew(l);
	else
	{
		temp = pf->res;
		pf->res = ft_strsub(temp, 0, (pf->len + l));
		free(temp);
	}
	l = l + pf->len;
	while (pf->len < l)
	{
		pf->res[pf->len] = c;
		pf->len++;
	}
}

void		repeat_print_prec(t_arg *pf, int std, char c)
{
	int		l;
	char	*temp;

	l = pf->prec - std;
	if (l <= 0)
		return ;
	pf->width = pf->width - l;
	pf->prec = pf->prec - l;
	if (!pf->res)
		pf->res = ft_strnew(l);
	else
	{
		temp = pf->res;
		pf->res = ft_strsub(temp, 0, (pf->len + l));
		free(temp);
	}
	l = l + pf->len;
	while (pf->len < l)
	{
		pf->res[pf->len] = c;
		pf->len++;
	}
}
