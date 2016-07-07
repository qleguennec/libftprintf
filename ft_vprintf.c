/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:40:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:07:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int				ft_vprintf
	(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}
