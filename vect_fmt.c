/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 13:38:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/06 13:53:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_intern.h"

int				vect_fmt
	(t_vect *v, const char *format, ...)
{
	size_t		oldsize;
	va_list		ap;
	char		*fmt;

	va_start(ap, format);
	fmt = (char *)format;
	oldsize = v->used;
	while (eval_fmt(&fmt, ap, v))
		;
	va_end(ap);
	return (!*fmt * (v->used - oldsize));
}
