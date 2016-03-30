/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 23:00:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

typedef t_vect		*(* t_conv_f)(void *);
typedef struct		s_conv_spec
{
	char			name[3];
	t_conv_f		conv_f;
}					t_conv_spec;

t_vect				*d_conv(void *x);

static t_conv_spec	convs_arr[] =
{
	{ "d",  &d_conv },
};

#endif
