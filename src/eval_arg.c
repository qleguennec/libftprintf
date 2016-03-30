/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 23:30:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_vect				*build_result
	(t_vect *builder, t_attrs *attrs)
{
	(void)attrs;
	return (ft_lstbuild(builder->content));
}

t_vect				*eval_arg
	(t_printf_conf *conf, char **fmt, char *sep, void *arg)
{
	t_attr_spec		*as;
	t_conv_spec		*cs;
	t_attrs			*attrs;
	char			letter[3];

	ft_bzero(letter, 3);
	if (!(attrs = ft_memalloc(sizeof(*attrs))))
		p_exit(PRINTF_ERR_MALLOC, " in function eval_arg");
	while ((*letter = *sep)
		&& (as = (t_attr_spec *)bst_search(conf->attrs, letter, &cmp)))
	{
		ft_memset(attrs + as->offset, 0xFF, sizeof(int));
		sep++;
	}
	if (!(cs = (t_conv_spec *)bst_search(conf->convs, letter, &cmp)))
		p_exit(PRINTF_ERR_CONV, letter);
	*fmt = sep + 1;
	return (build_result(cs->conv_f(arg), attrs));
}
