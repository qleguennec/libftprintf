/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/14 18:05:49 by qle-guen         ###   ########.fr       */
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

size_t				parse_num
	(char **fmt, va_list *ap)
{
	int				arg;
	size_t			num;

	if (!**fmt)
		return (0);
	if (**fmt == '*')
	{
		(*fmt)++;
		arg = va_arg(*ap, int);
		if (arg < 0)
		{
			num = (size_t) - arg;
			num |= 0xF0000;
		}
		else
			num = (size_t)arg;
	}
	else if ((num = ft_atoi(*fmt)))
		*fmt += digits_nb((t_arg)num, 10);
	return (num);
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
