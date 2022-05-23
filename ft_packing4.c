/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_packing4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:55:36 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 16:24:47 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_n2(t_list *dcp, va_list *ap)
{
	signed char		*p3;
	long long int	*p4;
	int				*p5;

	if (dcp->flags[8] == '2')
	{
		p3 = va_arg(*ap, signed char*);
		*p3 = dcp->sfpr;
	}
	else if (dcp->flags[9] == '2')
	{
		p4 = va_arg(*ap, long long int*);
		*p4 = dcp->sfpr;
	}
	else
	{
		p5 = va_arg(*ap, int*);
		*p5 = dcp->sfpr;
	}
	return (0);
}

int	ft_n(t_list *dcp, va_list *ap)
{
	short int		*p1;
	long int		*p2;

	if (dcp->flags[6] == '2')
	{
		p1 = va_arg(*ap, short int*);
		*p1 = dcp->sfpr;
	}
	else if (dcp->flags[7] == '2')
	{
		p2 = va_arg(*ap, long int*);
		*p2 = dcp->sfpr;
	}
	else
		ft_n2(dcp, ap);
	ft_clean(dcp);
	return (0);
}
