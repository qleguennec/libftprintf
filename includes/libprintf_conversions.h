/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 16:39:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>

typedef struct		s_conv_spec
{
	char			name[1];
	t_vect 			*(* conv_f)(void *, struct s_conv_spec *);
	unsigned int	sign : 1;
	size_t			size;
	unsigned int	base : 2;
}					t_conv_spec;

t_vect				*i_conv(void *x, t_conv_spec *self);

static t_conv_spec	convs_arr[] =
{
	{"d", &i_conv, 1, sizeof(int), BASE10},
	{"i", &i_conv, 1, sizeof(int), BASE10},
	{"o", &i_conv, 0, sizeof(int), BASE10},
	{"x", &i_conv, 0, sizeof(int), BASE16LOW},
	{"X", &i_conv, 0, sizeof(int), BASE16UP},
};

#endif
