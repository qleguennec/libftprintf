/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:09:59 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:51:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			cmp(void *a, void *b)
{
	char	s1[3];
	char	s2[3];

	ft_memcpy(s1, a, 3);
	ft_memcpy(s2, b, 3);
	printf("cmp: %s, %s\n", s1, s2);
	return (ft_strcmp(s1, s2));
}
