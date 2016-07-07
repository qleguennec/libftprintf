/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/06 13:46:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf_intern.h"

t_vect			*get_result
	(const char *format, va_list ap)
{
	char		*fmt;
	t_vect		*v;

	fmt = (char *)format;
	v = ft_memalloc(sizeof(*v));
	if (!v)
		return (NULL);
	while (eval_fmt(&fmt, ap, v))
		;
	return (!*fmt ? v : NULL);
}
