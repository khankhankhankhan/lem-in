/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_analyze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:26:23 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:38:29 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*arg_analyze(const char *format, va_list *ap, t_arg *pf)
{
	ft_pf_init(pf);
	format++;
	if (*format && ft_strchr("# 0+-123456789.*hljtzq", *format))
		format = get_flag(format, pf, ap);
	if (*format && ft_strchr("sSpdDioOuUxXcCfF", *format))
		ft_select(ap, format, pf);
	else
		ft_print_nosignal(pf, format);
	return (format);
}

const char	*get_modify(const char *format, t_arg *pf)
{
	while (*format && ft_strchr("hljtzq", *format))
	{
		if (*format == 'h' && pf->h == 1)
			pf->hh = 1;
		else if (*format == 'h')
			pf->h = 1;
		else if (*format == 'l' && pf->l == 1)
			pf->ll = 1;
		else if (*format == 'l')
			pf->l = 1;
		else if (*format == 'j')
			pf->j = 1;
		else if (*format == 't')
			pf->t = 1;
		else if (*format == 'z')
			pf->z = 1;
		else if (*format == 'q')
			pf->q = 1;
		format++;
	}
	return (format);
}

void		arg_process(va_list *ap, const char *format, t_arg *pf)
{
	char	*start;
	int		i;

	i = 0;
	start = (char*)format;
	while (*format)
	{
		if (*format == '%')
		{
			ft_print_join(pf, start, i);
			format = arg_analyze(format, ap, pf);
			i = -1;
			if (*format)
				start = (char *)(format + 1);
		}
		i++;
		format = (*format) ? format + 1 : format;
	}
	ft_print_join(pf, start, i);
}

void		ft_select(va_list *ap, const char *format, t_arg *pf)
{
	if (*format == 's' || *format == 'S')
		ft_print_s(ap, pf, *format);
	else if (*format == 'p')
		ft_print_point(ap, pf);
	else if (*format == 'd' || *format == 'D' || *format == 'i')
		ft_print_decimal(ap, pf, *format);
	else if (*format == 'o' || *format == 'O')
		ft_print_octal(ap, pf, *format);
	else if (*format == 'u' || *format == 'U')
		ft_print_undec(ap, pf, *format);
	else if (*format == 'x' || *format == 'X')
		ft_print_hex(ap, pf, *format);
	else if (*format == 'c' || *format == 'C')
		ft_print_ch(ap, pf, *format);
	else if (*format == 'f' || *format == 'F')
		ft_print_float(ap, pf);
}

void		ft_pf_init(t_arg *pf)
{
	pf->pound = 0;
	pf->plus = 0;
	pf->space = 0;
	pf->minus = 0;
	pf->zero = 0;
	pf->dot = 0;
	pf->width = 0;
	pf->prec = 0;
	pf->h = 0;
	pf->hh = 0;
	pf->l = 0;
	pf->ll = 0;
	pf->j = 0;
	pf->t = 0;
	pf->z = 0;
	pf->q = 0;
}
