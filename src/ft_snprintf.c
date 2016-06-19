/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:22:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 15:38:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				ft_snprintf
	(char *str, size_t size, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vsnprintf(str, size, format, ap));
}
