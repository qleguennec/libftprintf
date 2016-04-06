/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:09:59 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 18:27:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			basic_cmp
	(void *a, void *b)
{
	return (ft_strcmp(a, b));
}

int			fmt_spec_cmp
	(void *a, void *b)
{
	char	*s1;
	char	*s2;

	s1 = (char *)a;
	s2 = (char *)b;
	if (ft_strstr(s1, s2) == s1)
		return (0);
	else
		return (ft_strcmp(s1, s2));
}
