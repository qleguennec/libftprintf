/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:00:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 13:10:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>
#include <stdio.h>

t_list				*find_sep
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

int					get_conv_result
	(t_list **builder, t_parse_result *p)
{
	t_list			*l;
	char			letter;
	size_t			list_len;

	list_len = ft_lstsum(*builder);
	if ((unsigned int)p->ctxt.width <= list_len)
		return (ft_lstbuild(*builder));
	if (!(l = ft_lstnew(NULL, p->ctxt.width - list_len)))
		return (0);
	if (MINUS_MASK & p->ctxt.attrs)
		letter = ' ';
	else
		letter = ((ZERO_MASK & p->ctxt.attrs) ? '0' : ' ');
	ft_memset(l->content, letter, p->ctxt.width - list_len);
	if (letter == ' ' || !(*builder)->next
		|| ((MINUS_MASK) & p->ctxt.attrs))
	{
		if (MINUS_MASK & p->ctxt.attrs)
			return (ft_lstbuild(ft_lstadd_end(builder, l)));
		else
			return (ft_lstbuild(ft_lstadd(builder, l)));
	}
	l->next = (*builder)->next;
	(*builder)->next = l;
	return (ft_lstbuild(*builder));
}

static void			parse_fmt
	(t_parse_result *p_res, char **fmt, t_printf_conf *conf)
{
	(*fmt)++;
	p_res->ctxt.attrs = parse_attrs(fmt, conf);
	p_res->ctxt.width = parse_width(fmt);
	p_res->ctxt.prec = parse_prec(fmt);
	p_res->ctxt.l_modif = parse_l_modif(fmt, conf);
	p_res->conv = parse_conv(fmt, conf);
}

t_list				*eval_fmt
	(char **fmt, va_list *ap, t_printf_conf *conf)
{
	char			*start;
	t_list			*ret;
	t_parse_result	p_res;

	if (!**fmt)
		return (NULL);
	if (**fmt != '%')
		return (find_sep(fmt));
	ret = NULL;
	ft_bzero(&p_res, sizeof(p_res));
	parse_fmt(&p_res, fmt, conf);
	if (!p_res.conv)
	{
		start = *fmt;
		*fmt += ft_strlen(*fmt);
		return (ft_lstnew(start, *fmt - start));
	}
	if (p_res.conv->size)
		p_res.ctxt.arg = va_arg(*ap, t_arg);
	ft_lstadd(&ret, p_res.conv->conv_f(&p_res));
	ft_lstadd(&ret, eval_attrs(p_res.conv, &p_res.ctxt));
	get_conv_result(&ret, &p_res);
	return (ret);
}
