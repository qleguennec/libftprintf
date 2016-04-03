/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/03 02:14:41 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>

typedef struct		s_conv_spec
{
	char			name;
	t_list
		*(* conv_f)(struct s_conv_spec *, void *, size_t);
	unsigned int	sign : 2;
	size_t			size;
	unsigned int	base : 3;
}					t_conv_spec;

t_list				*i_conv
	(t_conv_spec *self, void *x, size_t precision);
t_list				*s_conv
	(t_conv_spec *self, void *x, size_t precision);

static t_conv_spec	convs_arr[] =
{
	{'d', &i_conv, 1, sizeof(int), BASE10},
	{'i', &i_conv, 1, sizeof(int), BASE10},
	{'o', &i_conv, 0, sizeof(int), BASE8},
	{'x', &i_conv, 0, sizeof(int), BASE16LOW},
	{'X', &i_conv, 0, sizeof(int), BASE16UP},
	{'s', &s_conv, 0, sizeof(int), BASE16UP},
};

#endif
