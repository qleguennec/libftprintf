/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:37:52 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static unsigned int	parse_attrs
	(char **fmt, t_printf_conf *conf)
{
	t_attr_spec		*as;
	unsigned int	attrs;

	attrs = 0;
	while ((as = bst_search(conf->attrs, *fmt, &fmt_conv_cmp)))
	{
		attrs |= as->mask;
		(*fmt)++;
	}
	return (attrs);
}

static int			parse_width
	(char **fmt)
{
	size_t			width;

	width = ft_atoi(*fmt);
	if (width)
		*fmt += digits_nb((t_arg)width, 10);
	return (width);
}

static int			parse_prec
	(char **fmt)
{
	size_t			prec;

	if (**fmt != '.')
		return (0);
	(*fmt)++;
	prec = ft_atoi(*fmt);
	if (prec)
		*fmt += digits_nb((t_arg)prec, 10);
	return (prec);
}

static t_conv_spec	*parse_conv
	(char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*found;

	if (!**fmt || !(found = 
		bst_search(conf->convs, *fmt, &fmt_conv_cmp)))
		return (NULL);
	*fmt += ft_strlen(found->name);
	return (found);
}

t_list				*parse_fmt
	(char **fmt, va_list ap, t_printf_conf *conf)
{
	t_list			*ret;
	t_ctxt_spec		ctxt;
	t_conv_spec		*cs;
	char			*buf;

	if (!**fmt)
		return (NULL);
	if (**fmt != '%')
		return (find_sep(fmt));
	buf = (*fmt)++;
	ft_bzero(&ctxt, sizeof(ctxt));
	ctxt.attrs = parse_attrs(fmt, conf);
	ctxt.width = parse_width(fmt);
	ctxt.prec = parse_prec(fmt);
	if (!(cs = parse_conv(fmt, conf)))
	{
		*fmt = buf + ft_strlen(buf);
		return (buf - *fmt > 1 ?
			ft_lstnew(buf, ft_strlen(buf)) : NULL);
	}
	if (cs->size)
		ctxt.arg = va_arg(ap, t_arg);
	ret = cs->conv_f(cs, &ctxt);
	ft_lstadd(&ret, eval_attrs(cs, &ctxt));
	get_conv_result(&ret, &ctxt);
	return (ret);
}
