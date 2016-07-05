/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 18:33:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_intern.h"

unsigned int		parse_attrs
	(char **fmt)
{
	t_attr_spec		*as;
	unsigned int	attrs;
	char			fmt_cpy[2];
	void			*fst;
	void			*lst;

	if (!**fmt)
		return (0);
	attrs = 0;
	*fmt_cpy = **fmt;
	fmt_cpy[1] = '\0';
	fst = g_attrs_arr;
	lst = fst + sizeof(*as) * (LEN(g_attrs_arr) - 1);
	while ((as = ft_find(fmt_cpy, fst, lst, sizeof(*as))))
	{
		attrs |= as->mask;
		(*fmt)++;
		*fmt_cpy = **fmt;
	}
	return (attrs);
}

size_t				parse_num
	(char **fmt, va_list ap)
{
	int				arg;
	size_t			num;

	if (!**fmt)
		return (0);
	if (**fmt == '*')
	{
		arg = va_arg(ap, int);
		if (ft_isdigit(*++(*fmt)))
			return (parse_num(fmt, ap));
		if (arg < 0)
		{
			num = (size_t)-arg;
			num |= (size_t)0xF << 32;
		}
		else
			num = (size_t)arg;
		return (num);
	}
	num = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	return (**fmt != '*' ? num : parse_num(fmt, ap));
}

t_l_modif_spec		*parse_l_modif
	(char **fmt)
{
	t_l_modif_spec	*found;
	char			fmt_cpy[3];
	void			*fst;
	void			*lst;

	if (!**fmt)
		return (NULL);
	ft_memcpy(fmt_cpy, *fmt, 2);
	fmt_cpy[2] = '\0';
	if (!(fmt_cpy[1] == 'l' || fmt_cpy[1] == 'h'))
		fmt_cpy[1] = '\0';
	fst = g_l_modifs_arr;
	lst = fst + sizeof(*found) * (LEN(g_l_modifs_arr) - 1);
	if (!(found = ft_find(fmt_cpy, fst, lst, sizeof(*found))))
		return (NULL);
	*fmt += ft_strlen(found->name);
	return (found);
}

t_conv_spec			*parse_conv
	(char **fmt)
{
	t_conv_spec		*found;
	char			fmt_cpy[2];
	void			*fst;
	void			*lst;

	if (!**fmt)
		return (NULL);
	*fmt_cpy = **fmt;
	fmt_cpy[1] = '\0';
	fst = g_convs_arr;
	lst = fst + sizeof(*found) * (LEN(g_convs_arr) - 1);
	if (!(found = ft_find(fmt_cpy, fst, lst, sizeof(*found))))
		return (NULL);
	*fmt += ft_strlen(found->name);
	return (found);
}
