/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:16:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 14:24:50 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <unistd.h>

int				ft_dprintf
	(int fd, const char *format, ...)
{
	va_list		ap;
	t_vect		*res;
	size_t		len;

	va_start(ap, fd);
	res = get_result(format, &ap);
	len = res->used;
	write(fd, res->data, len);
	vect_del(&res);
	return (len);
}
