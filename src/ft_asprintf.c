/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:51:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 14:52:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				ft_asprintf
	(char **ret, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vasprintf(ret, format, ap));
}
