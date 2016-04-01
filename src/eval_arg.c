/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 18:56:42 by qle-guen         ###   ########.fr       */
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
	s -= builder->size;
	ft_lstdel((t_list **)&builder->content, &ft_delete);
	builder->content = s;
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
	t_vect			*builder;
	t_attrs			attrs;
	char			letter[3];

	attrs = 0;
	ft_bzero(letter, 3);
	while ((*letter = *sep)
		&& (as = (t_attr_spec *)bst_search(conf->attrs, letter, &cmp)))
	{
		attrs |= 1 << as->offset;
		sep++;
	}
	if (!(cs = (t_conv_spec *)bst_search(conf->convs, letter, &cmp)))
		p_exit(PRINTF_ERR_CONV, letter);
	builder = cs->conv_f(arg, cs);
	init_builder(builder);
	*fmt = sep + 1;
	return (build_result(builder, &attrs));
}
