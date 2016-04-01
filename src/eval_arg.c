/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 23:26:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static void			get_result
	(t_vect *builder)
{
	t_list			*l;
	char			*s;

	l = (t_list *)builder->content;
	s = malloc(builder->size);
	while (l)
	{
		ft_memcpy(s, l->content, l->content_size);
		s += l->content_size;
		l = l->next;
	}
	ft_lstdel((t_list **)&builder->content, &ft_delete);
	builder->content = s - builder->size;
}

static t_vect		*build_result
	(t_vect *builder, t_attrs *attrs)
{
	(void)attrs;
	if (!builder)
		p_exit(PRINTF_ERR_BUILD, NULL);
	get_result(builder);
	return (builder);
}

static void			init_builder
	(t_vect *v)
{
	t_list			*l;

	if (!(l = ft_memalloc(sizeof(*l))))
		p_exit(PRINTF_ERR_MALLOC, " in function init_builder");
	l->content = v->content;
	l->content_size = v->size;
	v->content = l;
}

t_vect				*eval_arg
	(t_printf_conf *conf, char **fmt, char *sep, void *arg)
{
	t_attr_spec		*as;
	t_conv_spec		*cs;
	t_conv_spec		self;
	t_vect			*builder;
	t_attrs			attrs;

	attrs = 0;
	while ((as = bst_search(conf->attrs, sep, &cmp)))
	{
		attrs |= 1 << as->offset;
		sep++;
	}
	if (!(cs = (bst_search(conf->convs, sep, &cmp))))
		p_exit(PRINTF_ERR_CONV, sep);
	ft_memcpy(&self, cs, sizeof(self));
	builder = self.conv_f(&self, arg);
	init_builder(builder);
	eval_attrs(&self, builder, attrs, arg);
	*fmt = sep + 1;
	return (build_result(builder, &attrs));
}
