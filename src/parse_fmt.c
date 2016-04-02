/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 23:27:33 by qle-guen         ###   ########.fr       */
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
		p_exit(PRINTF_ERR_CONV, *fmt);
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

t_list				*parse_fmt
	(char **fmt, void ***args, t_printf_conf *conf)
{
	t_list			*ret;
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
	ft_lstadd(&ret, parse_conv(&cs, **args, fmt, conf));
	ft_lstadd(&ret, eval_attrs(&cs, **args, attrs));
	(*args)++;
	if (!ft_lstbuild(ret))
		p_exit(PRINTF_ERR_BUILD, *fmt);
	return (ret);
}