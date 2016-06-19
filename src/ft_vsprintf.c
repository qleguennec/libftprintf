/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:25:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/19 15:26:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <limits.h>

int				ft_vsprintf
	(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, INT_MAX + 1, format, ap));
}
