/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:55:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:39:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

void		init_conversions(void)
{
	size_t	length;
	size_t	elem_size;

	length = sizeof(conversions_arr) / sizeof(t_conv_spec);
	elem_size = sizeof(t_conv_spec);
	conversions = bst_fromarray(conversions_arr, length, elem_size, &cmp);
	if (!conversions)
		p_exit(PRINTF_ERR_MALLOC, " in function init_conversions");
}

void		init_attributes(void)
{
	size_t	length;
	size_t	elem_size;

	length = sizeof(attributes_arr) / sizeof(t_attr_spec);
	elem_size = sizeof(t_attr_spec);
	attributes = bst_fromarray(conversions_arr, length, elem_size, cmp);
	if (!attributes)
		p_exit(PRINTF_ERR_MALLOC, " in function init_attributes");
}

void		init(void)
{
	if (!conversions)
		init_conversions();
	if (!attributes)
		init_attributes();
}
