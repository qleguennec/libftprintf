/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:16:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:04:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_dprintf
	(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
