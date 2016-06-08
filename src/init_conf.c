/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:55:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/08 20:05:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

t_bst_tree			*init_convs(void)
{
	size_t			length;
	size_t			elem_size;
	t_bst_tree		*convs;

	length = sizeof(g_convs_arr) / sizeof(t_conv_spec);
	elem_size = sizeof(t_conv_spec);
	convs = bst_fromarray(g_convs_arr, length, elem_size, &cmp);
	if (!convs)
		return (NULL);
	return (convs);
}

t_bst_tree			*init_attrs(void)
{
	size_t			length;
	size_t			elem_size;
	t_bst_tree		*attrs;

	length = sizeof(g_attrs_arr) / sizeof(t_attr_spec);
	elem_size = sizeof(t_attr_spec);
	attrs = bst_fromarray(g_attrs_arr, length, elem_size, &cmp);
	if (!attrs)
		return (NULL);
	return (attrs);
}

t_bst_tree			*init_l_modifs(void)
{
	size_t			length;
	size_t			elem_size;
	t_bst_tree		*l_modifs;

	length = sizeof(g_l_modifs_arr) / sizeof(t_l_modif_spec);
	elem_size = sizeof(t_l_modif_spec);
	l_modifs = bst_fromarray(g_l_modifs_arr, length, elem_size, &cmp);
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
