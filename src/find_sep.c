/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:09:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:23:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list				*find_sep
	(char **fmt)
{
	t_list			*ret;
	char			*sep;

	(sep = ft_strchr(*fmt, '%')) || (sep = ft_strend(*fmt));
	if (!(ret = ft_lstnew(*fmt, sep - *fmt)))
		return (NULL);
	*fmt = sep;
	return (ret);
}
