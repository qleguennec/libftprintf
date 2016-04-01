/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_attributes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:29:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/31 12:28:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_ATTRIBUTES_H
# define LIBPRINTF_ATTRIBUTES_H

typedef short		t_attrs;

typedef struct		s_attr_spec
{
	char			name[3];
	int				offset;
}					t_attr_spec;

static t_attr_spec	attrs_arr[] =
{
	{"#\000\000",	0},
	{"0\000\000",	1},
	{"-\000\000",	2},
	{" \000\000",	3},
	{"+\000\000",	4},
};

#endif
