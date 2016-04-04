/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/04 13:57:23 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list			*s_conv
	(t_conv_spec *self)
{
	t_list		*ret;
	size_t		len;
	char		*s;

	s = (char *)self->arg;
	len = (s ? ft_strlen(s) - 1 : 6);
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	if (s)
		ft_memcpy(ret->content, s, len);
	else
		ft_memcpy(ret->content, "(null)", len);
	return (ret);
}
