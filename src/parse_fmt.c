/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/03 22:30:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_attrs		parse_attrs
	(char **fmt, t_printf_conf *conf)
{
	t_attr_spec		*as;
	t_attrs			attrs;

	attrs = 0;
	while ((as = bst_search(conf->attrs, *fmt, &cmp)))
	{
		attrs |= 1 << as->offset;
		(*fmt)++;
	}
	return (attrs);
}

static t_list		*parse_conv
	(t_conv_spec *cs, void *arg, char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*search;

	if (!(search = bst_search(conf->convs, *fmt, &cmp)))
		return (NULL);
	ft_memcpy(cs, search, sizeof(*cs));
	(*fmt)++;
	return (cs->conv_f(cs, arg, 0));
}

static t_list		*find_sep
	(char **fmt)
{
	t_list			*ret;
	char			*sep;

	if (!(sep = ft_strchr(*fmt, '%')))
		sep = ft_strchr(*fmt, '\0');
	if (!(ret = ft_lstnew(*fmt, sep - *fmt)))
		return (NULL);
	*fmt = sep;
	return (ret);
}

int					get_result
	(t_list **builder, t_conv_spec *cs, int width, t_attrs attrs)
{
	t_list			*l;
	char			letter;
	size_t			list_len;

	list_len = ft_lstsum(*builder);
	if ((unsigned int)width <= list_len || (cs->sign >> 1))
		return (ft_lstbuild(*builder));
	if (!(l = ft_lstnew(NULL, width - list_len)))
		return (0);
	if ((1 << MINUS_OFFSET) & attrs)
		letter = ' ';
	else
		letter = ((1 << ZERO_OFFSET ? '0' : ' '));
	ft_memset(l->content, letter, width - list_len);
	if (!(*builder)->next || ((1 << MINUS_OFFSET) & attrs))
	{
		if ((1 << MINUS_OFFSET) & attrs)
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
	void			*arg;
	int				width;
	t_attrs			attrs;
	t_conv_spec		cs;

	ret = NULL;
	if (!**fmt)
		return (NULL);
	if (**fmt != '%')
		return (find_sep(fmt));
	(*fmt)++;
	attrs = parse_attrs(fmt, conf);
	width = ft_atoi(*fmt);
	*fmt += (width ? digits_nb((unsigned long)width, 10) : 0);
	arg = va_arg(ap, void *);
	ft_lstadd(&ret, parse_conv(&cs, arg, fmt, conf));
	ft_lstadd(&ret, eval_attrs(&cs, arg, attrs));
	if (!get_result(&ret, &cs, width, attrs))
		return (NULL);
	return (ret);
}
