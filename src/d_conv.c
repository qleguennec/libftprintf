/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 19:35:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_vect		*d_conv
	(void *x)
{
	char	*buf;
	t_list	*build;
	t_vect	*builder;

	if (!((buf = ft_itoa((*(int*)x)))
		&& (builder = malloc(sizeof(*builder)))
		&& (build = malloc(sizeof(*build)))))
	{
		return (NULL);
		p_exit(PRINTF_ERR_MALLOC, " in function d_conv");
	}
	build->content = buf;
	build->content_size = ft_strlen(buf);
	builder->content = build;
	return (builder);
}
