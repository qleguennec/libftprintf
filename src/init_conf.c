/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:55:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 22:57:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_bst_tree			*init_convs(void)
{
	size_t			length;
	size_t			elem_size;
	t_bst_tree		*convs;

	length = sizeof(convs_arr) / sizeof(t_conv_spec);
	elem_size = sizeof(t_conv_spec);
	convs = bst_fromarray(convs_arr, length, elem_size, &cmp);
	if (!convs)
		p_exit(PRINTF_ERR_MALLOC, " in function init_convs");
	return (convs);
}

t_bst_tree			*init_attrs(void)
{
	size_t			length;
	size_t			elem_size;
	t_bst_tree		*attrs;

	length = sizeof(attrs_arr) / sizeof(t_attr_spec);
	elem_size = sizeof(t_attr_spec);
	attrs = bst_fromarray(attrs_arr, length, elem_size, cmp);
	if (!attrs)
		p_exit(PRINTF_ERR_MALLOC, " in function init_attrs");
	return (attrs);
}

t_printf_conf		*init_conf(void)
{
	t_printf_conf	*conf;

	printf("init called\n");
	conf = malloc(sizeof(*conf));
	conf->convs = init_convs();
	conf->attrs = init_attrs();
	return (conf);
}
