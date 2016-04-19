/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:58:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/19 15:14:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list		*null_case
	(t_parse_result *p)
{
	size_t	len;

	len = ft_strlen(p->conv->null_case);
	if (!len)
		len = 1;
	if (!p->ctxt.prec)
		return (NULL);
	else
		return (ft_lstnew(p->conv->null_case, len));
}
