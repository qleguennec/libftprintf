/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 13:33:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 18:55:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test(char *fmt, char **pf, char **ftpf, ...)
{
	int ret, ret1;
	va_list l, l1;

	va_start(l, ftpf);
	va_copy(l1, l);
	ret = vasprintf(pf, fmt, l);
	ret1 = ft_vasprintf(ftpf, fmt, l1);
	ft_printf("pf ret\t%d\n", ret);
	ft_printf("pf out\t%s\n", *pf);
	ft_printf("ft ret\t%d\n", ret1);
	ft_printf("ft out\t%s\n", *ftpf);
	va_end(l);
	if (ret != ret1)
		return (1);
	return (strcmp(*pf, *ftpf));
}

int main()
{
	char *pf, *ftpf = NULL;
	int c = 42;;

	return (test("%s%u%d", &pf, &ftpf, "sad", 42, 1000000));
}
