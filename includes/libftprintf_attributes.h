/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_attributes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:29:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/09 08:30:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_ATTRIBUTES_H
# define LIBFTPRINTF_ATTRIBUTES_H

# define SHARP_MASK	(1 << 0)
# define ZERO_MASK	(1 << 1)
# define MINUS_MASK	(1 << 2)
# define SPACE_MASK	(1 << 3)
# define PLUS_MASK	(1 << 4)

typedef char		t_attrs;

typedef struct		s_attr_spec
{
	char			name[3];
	unsigned int	mask : 5;
}					t_attr_spec;

static t_attr_spec	g_attrs_arr[] =
{
	{"#", SHARP_MASK},
	{"0", ZERO_MASK},
	{"-", MINUS_MASK},
	{" ", SPACE_MASK},
	{"+", PLUS_MASK},
};

#endif
