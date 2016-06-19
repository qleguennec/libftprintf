/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:00:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 14:58:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <unistd.h>

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

static void			parse_fmt
	(t_parse_result *p_res, char **fmt, va_list ap)
{
	if (**fmt == '%')
		(*fmt)++;
	p_res->ctxt.attrs = parse_attrs(fmt);
	p_res->ctxt.width = parse_num(fmt, ap);
	if (p_res->ctxt.width & (size_t)0xF << 32)
	{
		p_res->ctxt.width &= (size_t)0xFFFFFFFF;
		p_res->ctxt.attrs |= MINUS_MASK;
	}
	if (**fmt == '.')
	{
		(*fmt)++;
		p_res->ctxt.prec_given = 1;
		p_res->ctxt.prec = parse_num(fmt, ap);
		if (p_res->ctxt.prec & (size_t)0xF << 32)
		{
			p_res->ctxt.prec_given = 0;
			p_res->ctxt.prec = 1;
		}
	}
	p_res->ctxt.l_modif = parse_l_modif(fmt);
	p_res->conv = parse_conv(fmt);
}

int					eval_fmt
	(char **fmt, va_list ap, t_vect **v)
{
	t_parse_result	p_res;

	if (!**fmt)
		return (0);
	if (**fmt != '%')
		return (find_sep(fmt, v));
	if (!*(*fmt + 1))
		return (0);
	ft_bzero(&p_res, sizeof(p_res));
	p_res.ctxt.prec = 1;
	parse_fmt(&p_res, fmt, ap);
	if (!p_res.conv)
		return ((**fmt ? vect_add(v, (*fmt)++, 1) : 0)
			&& eval_post(&p_res, v));
	if (p_res.conv->size)
		p_res.ctxt.arg = va_arg(ap, t_arg);
	if (!(p_res.conv->conv_f(&p_res, v) && eval_post(&p_res, v)))
		return (0);
	return (1);
}
