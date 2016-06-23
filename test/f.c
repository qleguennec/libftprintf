/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:45:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/23 00:31:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <libftprintf.h>
#include <libftprintf_intern.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int test()
{
	double x;
	int prec;
	char *pf;
	char *ftpf;

	x = ((double)rand()/(double)RAND_MAX) + (rand() % 2 ? rand() : 0);
	prec = rand() % PREC_MAX;
	pf = NULL;
	ftpf = NULL;
	printf("x\t%.30f\n", x);
	ft_printf("prec\t%d\n", prec);
	ft_asprintf(&ftpf, "%.*f", prec, x);
	asprintf(&pf, "%.*f", prec, x);
	ft_printf("ftpf\t%s\n", ftpf);
	ft_printf("pf\t%s\n", pf);
	return (strcmp(pf, ftpf) == 0);
}

int main()
{
	int t = NB_TESTS;
	int i = 0;
	int pass = 0;
	int ret;
	while (i < t)
	{
		ret = test();
		ft_printf(">%d\t%s\n", i++, ret ? "OK" : "NOK");
		ft_printf("-----\n");
		if (!ret)
		{
			pass--;
			break;
		}
		pass++;
	}
	ft_printf("%d/%d passed\n", pass, t);
	return (t == pass ? 0 : 1);
}
