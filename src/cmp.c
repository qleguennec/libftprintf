/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:09:59 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 19:54:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			basic_cmp
	(void *a, void *b)
{
	char	*sa;
	char	*sb;
	size_t	lena;
	size_t	lenb;

	sa = (char *)a;
	sb = (char *)b;
	lena = ft_strlen(sa);
	lenb = ft_strlen(sb);
	if (lena > lenb)
		return (1);
	if (lenb > lena)
		return (-1);
	return (ft_memcmp(a, b, lena));
}

int			fmt_spec_cmp
	(void *a, void *b)
{
	char	*fmt;
	char	*spec;
	size_t	len;

	fmt = (char *)a;
	spec = (char *)b;
	len = ft_strlen(spec);
	if (len > ft_strlen(fmt))
		return (ft_strcmp(a, b));
	if (len == 1)
		len = 2;
	return (ft_memcmp(fmt, spec, len - 1));
}
