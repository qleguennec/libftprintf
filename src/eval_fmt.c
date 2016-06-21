/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:00:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/21 11:27:45 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static int			find_sep
	(char **fmt, t_vect **v)
{
	char			*sep;

	sep = ft_strchr(*fmt, '%');
	if (!sep)
		sep = ft_strend(*fmt);
	if (!(vect_add(v, *fmt, sep - *fmt)))
		return (0);
	*fmt = sep;
	return (1);
}

static void			save_arg
	(t_parse_result *p, va_list ap)
{
	if (p->conv->size == 1)
		p->ctxt.arg.d = va_arg(ap, double);
	if (p->conv->size > 1)
		p->ctxt.arg.g = va_arg(ap, size_t);
}

static void			parse_fmt
	(t_parse_result *p, char **fmt, va_list ap)
{
	if (**fmt == '%')
		(*fmt)++;
	p->ctxt.attrs = parse_attrs(fmt);
	p->ctxt.width = parse_num(fmt, ap);
	if (p->ctxt.width & (size_t)0xF << 32)
	{
		p->ctxt.width &= (size_t)0xFFFFFFFF;
		p->ctxt.attrs |= MINUS_MASK;
	}
	if (**fmt == '.')
	{
		(*fmt)++;
		p->ctxt.prec_given = 1;
		p->ctxt.prec = parse_num(fmt, ap);
		if (p->ctxt.prec & (size_t)0xF << 32)
		{
			p->ctxt.prec_given = 0;
			p->ctxt.prec = 1;
		}
	}
	p->ctxt.l_modif = parse_l_modif(fmt);
	if ((p->conv = parse_conv(fmt)))
		save_arg(p, ap);
}

int					eval_fmt
	(char **fmt, va_list ap, t_vect **v)
{
	t_parse_result	p;

	if (!**fmt)
		return (0);
	if (**fmt != '%')
		return (find_sep(fmt, v));
	if (!*(*fmt + 1))
		return (0);
	ft_bzero(&p, sizeof(p));
	ft_bzero(&p.ctxt.arg, sizeof(t_arg));
	p.ctxt.prec = 1;
	parse_fmt(&p, fmt, ap);
	if (!p.conv)
		return ((**fmt ? vect_add(v, (*fmt)++, 1) : 0)
			&& eval_post(&p, v));
	if (!(p.conv->conv_f(&p, v) && eval_post(&p, v)))
		return (0);
	return (1);
}
