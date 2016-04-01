/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_alphabets.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:52:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 23:05:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_ALPHABETS_H
# define LIBPRINTF_ALPHABETS_H

#define BASE2		0
#define BASE8		1
#define BASE10		2
#define BASE16LOW	3
#define BASE16UP	4

static char		*alphabets[] =
{
	"01",
	"01234567",
	"0123456789",
	"0123456789abcdef",
	"0123456789ABCDEF",
};

#endif
