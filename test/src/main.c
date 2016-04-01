/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:52:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 23:27:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>
#include <limits.h>

int			main(void)
{
	ft_printf("%#x\n", 0);
	ft_printf("%#X\n", 123);
	ft_printf("%#o\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
}
