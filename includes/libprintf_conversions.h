/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/05 02:23:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>
#include <stdint.h>

typedef uintmax_t	t_arg;

typedef struct		s_conv_spec
{
	char			name[4];
	char			null_case[10];
	t_arg			arg;
	t_list			*(* conv_f)(struct s_conv_spec *);
	unsigned int	neg : 1;
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
	unsigned int	attrs : 5;
}					t_conv_spec;

t_list				*i_conv
	(t_conv_spec *self);
t_list				*s_conv
	(t_conv_spec *self);
t_list				*percent
	(t_conv_spec *self);

static t_conv_spec	convs_arr[] =
{
	{"d", "0", 0, &i_conv, 0, sizeof(int), BASE10, 30, 0},
	{"i", "0", 0, &i_conv, 0, sizeof(int), BASE10, 30, 0},
	{"o", "0", 0, &i_conv, 0, sizeof(int), BASE8, 3, 0},
	{"x", "0", 0, &i_conv, 0, sizeof(int), BASE16LOW, 3, 0},
	{"X", "0", 0, &i_conv, 0, sizeof(int), BASE16UP, 0, 1},
	{"p", "(nil)", 0, &i_conv, 0, sizeof(void *), BASE16LOW, 1, 1},
	{"s","(null)", 0, &s_conv, 0, sizeof(char *), 0, 0, 0},
	{"%", "", 0, &percent, 0, 0, 0, 0, 0},
	{"D", "0", 0, &i_conv, 0, sizeof(long int), BASE10, 30, 0},
	{"ld", "0", 0, &i_conv, 0, sizeof(int), BASE10, 30, 0},
	{"O", "0", 0, &i_conv, 0, sizeof(long int), BASE8, 3, 0},
	{"lo", "0", 0, &i_conv, 0, sizeof(long int), BASE8, 3, 0},
	{"U", "0", 0, &i_conv, 0, sizeof(int), BASE10LOW, 3, 0},
	{"lu", "0", 0, &i_conv, 0, sizeof(int), BASE10LOW, 3, 0},
};

#endif
