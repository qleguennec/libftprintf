/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:58:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/18 14:16:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list		*null_case
	(t_conv_spec *self)
{
	size_t	len;

	len = ft_strlen(self->null_case);
	if (!len)
		len = 1;
	return (ft_lstnew(self->null_case, len));
}
