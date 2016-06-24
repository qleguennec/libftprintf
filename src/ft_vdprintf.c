/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:31:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 18:48:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <unistd.h>
#include <limits.h>

int				ft_vdprintf
	(int fd, const char *format, va_list ap)
{
	t_vect		*v;
	size_t		len;

	v = get_result(format, ap);
	if (!v)
		return (-1);
	len = write(fd, v->data, v->used);
	vect_del(v);
	return (len <= INT_MAX ? len : -1);
}
