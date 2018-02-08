/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:47:38 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:34:23 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wchartostr(wchar_t const wc)
{
	char *conv;

	conv = ft_strnew(5);
	if (wc <= 0x7F)
		conv[0] = (char)wc;
	else if (wc <= 0x7FF)
	{
		conv[0] = (wc >> 6) + 0xC0;
		conv[1] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		conv[0] = (wc >> 12) + 0xE0;
		conv[1] = ((wc >> 6) & 0x3F) + 0x80;
		conv[2] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0x10FFFF)
	{
		conv[0] = (wc >> 18) + 0xF0;
		conv[1] = ((wc >> 12) & 0x3F) + 0x80;
		conv[2] = ((wc >> 6) & 0x3F) + 0x80;
		conv[3] = (wc & 0x3F) + 0x80;
	}
	return (conv);
}

void	ft_wstrtostr_preci(t_arg *pf, wchar_t const *src)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (*src && (i <= (size_t)pf->prec))
	{
		last = i;
		if (*src <= 0x7F)
			i++;
		else if (*src <= 0x7FF)
			i += 2;
		else if (*src <= 0xFFFF)
			i += 3;
		else if (*src <= 0x10FFFF)
			i += 4;
		if (*src)
			src++;
	}
	pf->prec = (i <= (size_t)pf->prec) ? i : last;
}

char	*ft_wstrtostr(wchar_t const *src)
{
	char *str;
	char *prev;
	char *next;

	if (!(str = ft_strnew(1)))
		return ((char *)NULL);
	while (*src)
	{
		prev = str;
		if (!(next = ft_wchartostr(*src)))
			return ((char *)NULL);
		if (!(str = ft_strjoin(prev, next)))
			return ((char *)NULL);
		if (*src)
			src++;
		ft_strdel(&prev);
		ft_strdel(&next);
	}
	return (str);
}

char	*ft_print_wstr(va_list *ap, t_arg *pf)
{
	wchar_t	*s;
	char	*str;

	s = va_arg(*ap, wchar_t*);
	if (!s)
		return (0);
	str = ft_wstrtostr(s);
	if (pf->dot == 1 || pf->prec > 0)
	{
		ft_wstrtostr_preci(pf, s);
		str = ft_strsub(str, 0, pf->prec);
	}
	return (str);
}

void	ft_print_s(va_list *ap, t_arg *pf, char c)
{
	char	*s;
	int		f;

	if (pf->l == 1 || c == 'S')
		s = ft_print_wstr(ap, pf);
	else
		s = va_arg(*ap, char*);
	f = (!s) ? 1 : 0;
	if (!s)
		s = "(null)";
	if (pf->dot == 0 || pf->prec >= (int)ft_strlen(s))
		pf->prec = (int)ft_strlen(s);
	if (pf->minus == 0 && pf->zero == 1)
		repeat_print_width(pf, pf->prec, '0');
	else if (pf->minus == 0 && pf->zero == 0)
		repeat_print_width(pf, pf->prec, ' ');
	ft_print_join(pf, s, pf->prec);
	if (pf->minus == 1)
		repeat_print_width(pf, pf->prec, ' ');
	if ((pf->l == 1 || c == 'S') && !f)
		free(s);
}
