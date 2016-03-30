/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_attributes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:29:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 23:01:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_ATTRIBUTES_H
# define LIBPRINTF_ATTRIBUTES_H

typedef struct		s_attrs
{
	int				sharp;
	int				zero;
	int				minus;
	int				space;
	int				plus;
}					t_attrs;

typedef struct		s_attr_spec
{
	char			name[3];
	size_t			offset;
}					t_attr_spec;

static t_attr_spec	attrs_arr[] =
{
	{ "#", offsetof(t_attrs, sharp) },
};

#endif
