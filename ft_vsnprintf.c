/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:15:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:04:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf_intern.h"
#include <limits.h>

int				ft_vsnprintf
	(char *str, size_t size, const char *format, va_list ap)
{
	t_vect		*v;
	size_t		len;

	if (!size)
		return (0);
	if (size == 1)
	{
		*str = '\0';
		return (1);
	}
	if (size > (size_t)INT_MAX + 1)
		return (-1);
	v = get_result(format, ap);
	if (!v)
		return (-1);
	len = MIN(size - 1, v->used);
	ft_memcpy(str, v->data, len);
	str[len] = '\0';
	len = v->used;
	vect_del(v);
	return (len <= INT_MAX ? len : -1);
}
