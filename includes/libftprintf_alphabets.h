/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_alphabets.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:52:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/09 08:29:50 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_ALPHABETS_H
# define LIBFTPRINTF_ALPHABETS_H

# define BASE2		0
# define BASE8		1
# define BASE10		2
# define BASE16LOW	3
# define BASE16UP	4

static char		*g_alphabets[] =
{
	"01",
	"01234567",
	"0123456789",
	"0123456789abcdef",
	"0123456789ABCDEF",
};

#endif
