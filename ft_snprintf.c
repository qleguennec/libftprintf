/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:22:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:04:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_snprintf
	(char *str, size_t size, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (ret);
}
