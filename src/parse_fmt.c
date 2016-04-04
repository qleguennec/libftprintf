/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/05 01:52:48 by qle-guen         ###   ########.fr       */
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

static t_list		*parse_conv
	(t_conv_spec *cs, va_list ap, char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*search;
	t_attrs			attrs;

	if (!(search = bst_search(conf->convs, *fmt, &fmt_conv_cmp)))
		return (NULL);
	attrs = cs->attrs;
	ft_memcpy(cs, search, sizeof(*cs));
	cs->attrs = cs->valid_attrs & attrs;
	if (cs->size)
		cs->arg = va_arg(ap, t_arg);
	*fmt += ft_strlen(cs->name);
	return (cs->conv_f(cs));
}

int					get_result
	(t_list **builder, t_conv_spec *cs, int width)
{
	t_list			*l;
	char			letter;
	size_t			list_len;

	list_len = ft_lstsum(*builder);
	if ((unsigned int)width <= list_len || (cs->neg))
		return (ft_lstbuild(*builder));
	if (!(l = ft_lstnew(NULL, width - list_len)))
		return (0);
	if (MINUS_MASK & cs->attrs)
		letter = ' ';
	else
		letter = ((ZERO_MASK & cs->attrs) ? '0' : ' ');
	ft_memset(l->content, letter, width - list_len);
	if (!(*builder)->next || ((MINUS_MASK) & cs->attrs))
	{
		if (MINUS_MASK & cs->attrs)
			ft_lstadd_end(builder, l);
		else
			ft_lstadd(builder, l);
		return (ft_lstbuild(*builder));
	}
	l->next = (*builder)->next;
	(*builder)->next = l;
	return (ft_lstbuild(*builder));
}

t_list				*parse_fmt
	(char **fmt, va_list ap, t_printf_conf *conf)
{
	t_list			*ret;
	int				width;
	t_conv_spec		cs;
	char			*buf;

	ret = NULL;
	if (!**fmt)
		return (NULL);
	if (**fmt != '%')
		return (find_sep(fmt));
	buf = (*fmt)++;
	ft_bzero(&cs, sizeof(cs));
	cs.attrs = parse_attrs(fmt, conf);
	width = ft_atoi(*fmt);
	*fmt += (width ? digits_nb((t_arg)width, 10) : 0);
	ft_lstadd(&ret, parse_conv(&cs, ap, fmt, conf));
	if (!ret && **fmt != '\0')
	{
		*fmt = buf + ft_strlen(buf);
		return (ft_lstnew(buf, ft_strlen(buf)));
	}
	ft_lstadd(&ret, eval_attrs(&cs));
	get_result(&ret, &cs, width);
	return (ret);
}
