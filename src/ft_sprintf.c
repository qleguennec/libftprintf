/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:27:28 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 15:28:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				ft_sprintf
	(char *str, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vsprintf(str, format, ap));
}
