/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:57:12 by qle-guen         ###   ########.fr       */
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

static t_conv_spec	conversions_arr[] =
{
	{ "d\000\000",  &d_conv },
};
static t_bst_tree	*conversions = NULL;


#endif
