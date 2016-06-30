/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:47:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:08:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_intern.h"

int				ft_vasprintf
	(char **ret, const char *format, va_list ap)
{
	t_vect		*v;
	size_t		len;

	v = get_result(format, ap);
	if (!v || !(*ret = ft_strnew(v->used)))
	{
		*ret = NULL;
		return (-1);
	}
	len = v->used;
	ft_memcpy(*ret, v->data, len);
	vect_del(v);
	return (len <= INT_MAX ? len : -1);
}
