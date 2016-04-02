/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:52:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/03 01:45:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>
#include <limits.h>

int			main(void)
{
	int i = 1;
	ft_printf("hello I'm ft_printf! I'll print 42 for you\n");
	ft_printf("ftp: %#010x\n", 42);
	printf("hello I'm printf! I'll print 42 for you\n");
	printf("  p: %#010x\n", 42);
	ft_printf("you should know that %+d is the maximum int\n", INT_MAX);
	ft_printf("you should know that %d is the minimum int\n", INT_MIN);
	ft_printf("%d - %d + %d * %d = 42\n", 12, 3, 12, 2);
	ft_printf("some tests:\n");
	ft_printf("ftp: %#-19x\n", -42);
	printf("  p: %#-19x\n", -42);
	ft_printf("ftp: %40d\n", -42);
	printf("  p: %-40d\n", -42);
	ft_printf("ftp: %010d\n", 42);
	ft_printf("  p: %010d\n", 42);
	ft_printf("ftp: % 10d\n", 42);
	ft_printf("  p: % 10d\n", 42);
}
