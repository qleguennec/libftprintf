/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_attributes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:29:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 23:12:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_ATTRIBUTES_H
# define LIBPRINTF_ATTRIBUTES_H

#define SHARP_OFFSET	0
#define ZERO_OFFSET		1
#define MINUS_OFFSET	2
#define SPACE_OFFSET	3
#define PLUS_OFFSET		4

typedef char		t_attrs;

typedef struct		s_attr_spec
{
	char			name;
	int				offset;
}					t_attr_spec;

static t_attr_spec	attrs_arr[] =
{
	{'#',	SHARP_OFFSET},
	{'0',	ZERO_OFFSET},
	{'-',	MINUS_OFFSET},
	{' ',	SPACE_OFFSET},
	{'+',	PLUS_OFFSET},
};

#endif
