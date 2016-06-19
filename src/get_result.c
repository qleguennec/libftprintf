/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 14:54:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

t_vect			*get_result
	(const char *format, va_list ap)
{
	char		*fmt;
	t_vect		*v;
	t_vect		*builder;

	fmt = (char *)format;
	builder = NULL;
	v = NULL;
	while (eval_fmt(&fmt, ap, &v))
	{
		if (!vect_add(&builder, v->data, v->used))
			return (NULL);
		v->used = 0;
	}
	vect_del(&v);
	return (builder);
}
