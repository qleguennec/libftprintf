/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 19:55:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

unsigned int		parse_attrs
	(char **fmt, t_printf_conf *conf)
{
	t_attr_spec		*as;
	unsigned int	attrs;

	attrs = 0;
	while ((as = bst_search(conf->attrs, *fmt, &fmt_spec_cmp)))
	{
		attrs |= as->mask;
		(*fmt)++;
	}
	return (attrs);
}

size_t				parse_width
	(char **fmt)
{
	size_t			width;

	width = ft_atoi(*fmt);
	if (width)
		*fmt += digits_nb((t_arg)width, 10);
	return (width);
}

size_t				parse_prec
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

size_t				parse_l_modif
	(char **fmt, t_printf_conf *conf)
{
	t_l_modif_spec	*found;

	if (!**fmt)
		return (0);
	if (!(found = bst_search(conf->l_modifs, *fmt, &fmt_spec_cmp)))
		return (0);
	*fmt += ft_strlen(found->name);
	return (found->size);
}

t_conv_spec			*parse_conv
	(char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*found;

	if (!**fmt) 
		return (NULL);
	if (!(found = bst_search(conf->convs, *fmt, &fmt_spec_cmp)))
		return (NULL);
	*fmt += ft_strlen(found->name);
	return (found);
}
