/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 02:20:11 by qle-guen         ###   ########.fr       */
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

static t_list		*find_sep
	(char **fmt)
{
	t_list			*ret;
	char			*sep;

	(sep = ft_strchr(*fmt, '%')) || (sep = ft_strend(*fmt));
	if (!(ret = ft_lstnew(*fmt, sep - *fmt)))
		return (NULL);
	*fmt = sep;
	return (ret);
}

static t_conv_spec	*parse_conv
	(va_list ap, char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*found;

	if (!**fmt || !(found = 
		bst_search(conf->convs, *fmt, &fmt_conv_cmp)))
		return (NULL);
	if (found->size)
		found->arg = va_arg(ap, t_arg);
	else
		ft_bzero(&found->arg, sizeof(found->arg));
	*fmt += ft_strlen(found->name);
	return (found);
}

int					get_result
	(t_list **builder, t_ctxt_spec *ctxt)
{
	t_list			*l;
	char			letter;
	size_t			list_len;

	list_len = ft_lstsum(*builder);
	if ((unsigned int)ctxt->width <= list_len)
		return (ft_lstbuild(*builder));
	if (!(l = ft_lstnew(NULL, ctxt->width - list_len)))
		return (0);
	if (MINUS_MASK & ctxt->attrs)
		letter = ' ';
	else
		letter = ((ZERO_MASK & ctxt->attrs) ? '0' : ' ');
	ft_memset(l->content, letter, ctxt->width - list_len);
	if (letter == ' ' || !(*builder)->next
		|| ((MINUS_MASK) & ctxt->attrs))
	{
		if (MINUS_MASK & ctxt->attrs)
			return (ft_lstbuild(ft_lstadd_end(builder, l)));
		else
			return (ft_lstbuild(ft_lstadd(builder, l)));
	}
	l->next = (*builder)->next;
	(*builder)->next = l;
	return (ft_lstbuild(*builder));
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
	ctxt.attrs = parse_attrs(fmt, conf);
	ctxt.width = ft_atoi(*fmt);
	*fmt += ctxt.width ? digits_nb((t_arg)ctxt.width, 10) : 0;
	ctxt.prec = **fmt == '.' ? ft_atoi(++(*fmt)) : 0;
	*fmt += ctxt.prec ? digits_nb((t_arg)ctxt.prec, 10) : 0;
	if (!(cs = parse_conv(ap, fmt, conf)))
	{
		*fmt = buf + ft_strlen(buf);
		return (buf - *fmt > 1 ?
			ft_lstnew(buf, ft_strlen(buf)) : NULL);
	}
	ret = cs->conv_f(cs, &ctxt);
	ft_lstadd(&ret, eval_attrs(cs, &ctxt));
	get_result(&ret, &ctxt);
	return (ret);
}
