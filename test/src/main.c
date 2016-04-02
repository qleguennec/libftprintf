/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:52:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 22:19:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>
#include <limits.h>

int			main(void)
{
	int i = 1;
	ft_printf("hello there printf! I'll print 42 for you\n");
	ft_printf("%#100x\n", 42);
	ft_printf("you should know that %+d is the maximum int\n", INT_MAX);
	ft_printf("you should know that %d is the minimum int\n", INT_MIN);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("call %d: %d\n", i++, 42);
	ft_printf("%d - %d + %d * %d = 42\n", 12, 3, 12, 2);
}
