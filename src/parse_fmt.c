/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 15:47:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static void		parse_attrs
	(char **fmt, t_attrs *attrs, t_printf_conf *conf)
{
	t_attr_spec		*as;

	while ((as = bst_search(conf->attrs, *fmt, &cmp)))
	{
		*attrs |= 1 << as->offset;
		(*fmt)++;
	}
}

static t_list	*parse_conv
	(char **fmt, void *arg, t_printf_conf *conf)
{
	t_conv_spec	*cs;

	if (!(cs = bst_search(conf->convs, *fmt, &cmp)))
		p_exit(PRINTF_ERR_CONV, *fmt);
	(*fmt)++;
	return (cs->conv_f(cs, arg, 0));
}

t_list				*parse_fmt
	(char **fmt, void ***args, t_printf_conf *conf)
{
	t_list			*ret;
	char			*sep;
	t_attrs			attrs;

	if (!**fmt)
		return (NULL);
	ret = NULL;
	sep = ft_strchr(*fmt, '%');
	if ((!sep && (sep = ft_strend(*fmt))) || sep != *fmt)
	{
		if (!(ret = ft_lstnew(*fmt, sep - *fmt)))
			return (NULL);
		*fmt = sep;
		return (ret);
	}
	*fmt = sep + 1;
	attrs = 0;
	parse_attrs(fmt, &attrs, conf);
	ft_lstadd(&ret, parse_conv(fmt, **args, conf));
	(**args)++;
	return (ret);
}
