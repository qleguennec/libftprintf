/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_attributes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:29:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:56:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_ATTRIBUTES_H
# define LIBPRINTF_ATTRIBUTES_H

typedef struct		s_attrs
{
	size_t			width;
	size_t			length;
	char			fill_char;
	int				fill_right;
}					t_attrs;

void				sharp_attr(t_attrs *a);

typedef void		(* t_attr_f)(t_attrs *);
typedef struct		s_attr_spec
{
	char			name[3];
	t_attr_f		attr_f;
}					t_attr_spec;

static t_attr_spec	attributes_arr[] =
{
	{ "#\000\000", &sharp_attr },
};

static t_bst_tree	*attributes = NULL;


#endif
