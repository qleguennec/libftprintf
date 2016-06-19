/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:15:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 15:21:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

int				ft_vsprintf
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
	v = get_result(format, ap);
	if (!v)
		return (-1);
	len = v->used;
	ft_memcpy(str, v->data, size - 1);
	str[size] = '\0';
	vect_del(&v);
	return (len);
}
