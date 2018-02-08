/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:27:36 by hkang             #+#    #+#             */
/*   Updated: 2017/12/01 13:26:06 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_arg
{
	char		*res;
	int			pound;
	int			plus;
	int			space;
	int			minus;
	int			zero;
	int			dot;
	int			width;
	int			prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			t;
	int			z;
	int			q;
	int			len;
}				t_arg;

void			ft_pf_init(t_arg *pf);
int				ft_printf(const char *format, ...);
void			arg_process(va_list *ap, const char *format, t_arg *pf);
const char		*arg_analyze(const char *format, va_list *ap, t_arg *pf);
void			ft_select(va_list *ap, const char *format, t_arg *pf);
char			*ft_llitoa_base(long long int value, int base);

void			ft_print_join(t_arg *pf, char *start, int i);

unsigned int	ft_getunsig_len(unsigned long long int value, int base);
unsigned int	ft_getsig_len(long long int value);
unsigned int	ft_getdouble_len(long double value, long double *limit);

const char		*get_flag(const char *format, t_arg *pf, va_list *ap);
const char		*get_modify(const char *format, t_arg *pf);
const char		*get_sig(const char *format, t_arg *pf);
const char		*get_width(const char *format, t_arg *pf, va_list *ap);
const char		*get_prec(const char *format, t_arg *pf, va_list *ap);

char			*ft_wchartostr(wchar_t const wc);
void			ft_wstrtostr_preci(t_arg *pf, wchar_t const *src);

void			ft_print_s(va_list *ap, t_arg *pf, char c);
int				ft_print_base(va_list *ap, int base);
void			ft_print_decimal(va_list *ap, t_arg *pf, char s);
void			ft_print_dec_right(char *res, t_arg *pf, int f);
void			ft_print_ch(va_list *ap, t_arg *pf, char c);
void			ft_print_octal(va_list *ap, t_arg *pf, char s);
void			ft_print_hex(va_list *ap, t_arg *pf, char s);
void			ft_print_nosignal(t_arg *pf, const char *format);
void			ft_print_point(va_list *ap, t_arg *pf);
void			ft_print_undec(va_list *ap, t_arg *pf, char s);
void			ft_print_float(va_list *ap, t_arg *pf);

char			*ft_itoa_base(uintmax_t num, uintmax_t base, int len, char c);
intmax_t		getnum_sig(va_list *ap, t_arg *pf);
uintmax_t		getnum_unsig(va_list *ap, t_arg *pf);

char			*get_int(va_list *ap, t_arg *pf, char s, int *f);
char			*get_hex(va_list *ap, t_arg *pf, char s);
char			*get_int_sig(t_arg *pf, int f);
int				get_float_bit(long double num, long double limit);

void			repeat_print_width(t_arg *pf, int std, char c);
void			repeat_print_prec(t_arg *pf, int std, char c);
#endif
