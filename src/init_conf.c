/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:55:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/15 15:19:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

t_bst_tree			*init_convs(void)
{
	size_t			elem_size;
	t_bst_tree		*convs;

	elem_size = sizeof(t_conv_spec);
	convs = bst_fromarray(g_convs_arr, LEN(g_convs_arr), elem_size, &cmp);
	if (!convs)
		return (NULL);
	return (convs);
}

t_bst_tree			*init_attrs(void)
{
	size_t			elem_size;
	t_bst_tree		*attrs;

	elem_size = sizeof(t_attr_spec);
	attrs = bst_fromarray(g_attrs_arr, LEN(g_attrs_arr), elem_size, &cmp);
	if (!attrs)
		return (NULL);
	return (attrs);
}

t_bst_tree			*init_l_modifs(void)
{
	size_t			elem_size;
	t_bst_tree		*l_modifs;

	elem_size = sizeof(t_l_modif_spec);
	l_modifs = bst_fromarray(g_l_modifs_arr,
			LEN(g_l_modifs_arr), elem_size, &cmp);
	if (!l_modifs)
		return (NULL);
	return (l_modifs);
}

t_printf_conf		*init_conf(void)
{
	t_printf_conf	*conf;

	conf = malloc(sizeof(*conf));
	conf->convs = init_convs();
	conf->attrs = init_attrs();
	conf->l_modifs = init_l_modifs();
	return (conf);
}
