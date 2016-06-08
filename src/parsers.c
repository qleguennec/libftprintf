/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/08 19:56:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

unsigned int		parse_attrs
	(char **fmt, t_printf_conf *conf)
{
	t_attr_spec		*as;
	unsigned int	attrs;
	char			fmt_cpy[2];

	if (!**fmt)
		return (0);
	attrs = 0;
	*fmt_cpy = **fmt;
	fmt_cpy[1] = '\0';
	while ((as = bst_search(conf->attrs, fmt_cpy, &cmp)))
	{
		attrs |= as->mask;
		(*fmt)++;
		*fmt_cpy = **fmt;
	}
	return (attrs);
}

size_t				parse_width
	(char **fmt)
{
	size_t			width;

	if (!**fmt)
		return (0);
	width = ft_atoi(*fmt);
	if (width)
		*fmt += digits_nb((t_arg)width, 10);
	return (width);
}

size_t				parse_prec
	(char **fmt)
{
	size_t			prec;

	if (!**fmt)
		return (0);
	prec = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	return (prec);
}

t_l_modif_spec		*parse_l_modif
	(char **fmt, t_printf_conf *conf)
{
	t_l_modif_spec	*found;
	char			fmt_cpy[3];

	if (!**fmt)
		return (NULL);
	ft_memcpy(fmt_cpy, *fmt, 2);
	fmt_cpy[2] = '\0';
	if (!(found = bst_search(conf->l_modifs, fmt_cpy, &cmp)))
	{
		fmt_cpy[1] = '\0';
		if (!(found = bst_search(conf->l_modifs, fmt_cpy, &cmp)))
			return (NULL);
	}
	*fmt += ft_strlen(found->name);
	return (found);
}

t_conv_spec			*parse_conv
	(char **fmt, t_printf_conf *conf)
{
	t_conv_spec		*found;
	char			fmt_cpy[2];

	if (!**fmt)
		return (NULL);
	*fmt_cpy = **fmt;
	fmt_cpy[1] = '\0';
	if (!(found = bst_search(conf->convs, fmt_cpy, &cmp)))
		return (NULL);
	*fmt += ft_strlen(found->name);
	return (found);
}
