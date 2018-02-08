/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:25:26 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:37:27 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	t_arg	*pf;

	len = 0;
	pf = (t_arg*)malloc(sizeof(t_arg));
	ft_pf_init(pf);
	pf->len = 0;
	pf->res = NULL;
	va_start(ap, format);
	arg_process(&ap, format, pf);
	va_end(ap);
	len = pf->len;
	write(1, pf->res, len);
	if (pf->len > 0)
		free(pf->res);
	free(pf);
	return (len);
}

const char	*get_sig(const char *format, t_arg *pf)
{
	while (*format && ft_strchr("# 0+-", *format))
	{
		if (*format == '#')
			pf->pound = 1;
		else if (*format == '+')
			pf->plus = 1;
		else if (*format == ' ')
			pf->space = 1;
		else if (*format == '-')
			pf->minus = 1;
		else if (*format == '0')
			pf->zero = 1;
		format++;
	}
	return (format);
}

const char	*get_prec(const char *format, t_arg *pf, va_list *ap)
{
	pf->dot = 1;
	format++;
	if (*format == '*')
	{
		pf->prec = va_arg(*ap, int);
		if (pf->prec < 0)
		{
			pf->prec = 0;
			pf->dot = 0;
		}
		format++;
	}
	else
	{
		pf->prec = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

const char	*get_width(const char *format, t_arg *pf, va_list *ap)
{
	while (*format && ft_strchr(".0123456789*", *format))
	{
		if (*format == '.' || pf->dot == 1)
			format = get_prec(format, pf, ap);
		else if (ft_isdigit(*format))
		{
			pf->width = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*')
		{
			pf->width = va_arg(*ap, int);
			if (pf->width < 0)
			{
				pf->width = -pf->width;
				pf->minus = 1;
			}
			format++;
		}
	}
	return (format);
}

const char	*get_flag(const char *format, t_arg *pf, va_list *ap)
{
	while (*format && ft_strchr("# 0+-hljtzq", *format))
	{
		format = get_sig(format, pf);
		format = get_modify(format, pf);
	}
	format = get_width(format, pf, ap);
	while (*format && ft_strchr("# 0+-hljtzq", *format))
	{
		format = get_sig(format, pf);
		format = get_modify(format, pf);
	}
	return (format);
}
