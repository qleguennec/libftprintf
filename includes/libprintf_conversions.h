/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 14:44:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>
#include <limits.h>
#include <stdint.h>

typedef uintmax_t	t_arg;

typedef struct		s_ctxt_spec
{
	unsigned int	attrs : 5;
	size_t			width;
	size_t			prec;
}					t_ctxt_spec;

typedef struct		s_conv_spec
{
	char			name[4];
	char			null_case[10];
	t_arg			arg;
	t_list			*(* conv_f)(struct s_conv_spec *, t_ctxt_spec *);
	unsigned int	neg : 1;
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
}					t_conv_spec;

t_list				*i_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*s_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*wc_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*wstr_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*percent
	(t_conv_spec *self, t_ctxt_spec *ctxt);

static t_conv_spec	convs_arr[] =
{
	{"d", "0", 0, &i_conv, 0, sizeof(int), BASE10, 30},
	{"u", "0", 0, &i_conv, 0, sizeof(int), BASE10, 3},
	{"c", "0", 0, &wc_conv, 0, sizeof(char), BASE10, 30},
	{"lc", "0", 0, &wc_conv, 0, sizeof(wchar_t), BASE10, 30},
	{"ls", "0", 0, &wstr_conv, 0, 1, 0, 0},
	{"i", "0", 0, &i_conv, 0, sizeof(int), BASE10, 3},
	{"o", "0", 0, &i_conv, 0, sizeof(int), BASE8, 3},
	{"x", "0", 0, &i_conv, 0, sizeof(int), BASE16LOW, 3},
	{"X", "0", 0, &i_conv, 0, sizeof(int), BASE16UP, 3},
	{"p", "(nil)", 0, &i_conv, 0, 0, BASE16LOW, 1},
	{"s","(null)", 0, &s_conv, 0, 1, 0, 0},
	{"%", "", 0, &percent, 0, 0, 0, 0},
	{"D", "0", 0, &i_conv, 0, sizeof(long int), BASE10, 30},
	{"ld", "0", 0, &i_conv, 0, sizeof(int), BASE10, 30},
	{"lld", "0", 0, &i_conv, 0, sizeof(long long int), BASE10, 30},
	{"O", "0", 0, &i_conv, 0, sizeof(long int), BASE8, 3},
	{"lo", "0", 0, &i_conv, 0, sizeof(long int), BASE8, 3},
	{"U", "0", 0, &i_conv, 0, sizeof(int), BASE10, 3},
	{"lu", "0", 0, &i_conv, 0, sizeof(int), BASE10, 3},
	{"llu", "0", 0, &i_conv, 0, sizeof(long long int), BASE10, 3},
};

#endif
