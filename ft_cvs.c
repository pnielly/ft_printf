/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:44:31 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/01 17:49:37 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_di(t_list *dcp, va_list *ap)
{
	if (dcp->flags[8] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->b = (signed char)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[9] == 2)
		dcp->c = va_arg(*ap, long long int);
	else if (dcp->flags[6] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->d = (short int)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[7] == 2)
		dcp->e = va_arg(*ap, long int);
	else
		dcp->a = va_arg(*ap, int);
	if (min_di(dcp) == 0)
		return (ft_convertbase(max_di(dcp), 10, 0, dcp->precision));
	else
		return (ft_convertbase(min_di(dcp), 10, 0, dcp->precision));
}

char	*ft_u(t_list *dcp, va_list *ap)
{
	if (dcp->flags[8] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->g = (unsigned char)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[9] == 2)
		dcp->h = va_arg(*ap, unsigned long long int);
	else if (dcp->flags[6] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->i = (unsigned short int)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[7] == 2)
		dcp->j = va_arg(*ap, unsigned long int);
	else
		dcp->f = va_arg(*ap, unsigned int);
	if (min_else(dcp) == 0)
		return (ft_convertbase_u(max_else(dcp), 10, 0, dcp->precision));
	else
		return (ft_convertbase_u(min_else(dcp), 10, 0, dcp->precision));
}

char	*ft_x(t_list *dcp, va_list *ap)
{
	if (dcp->flags[8] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->g = (unsigned char)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[9] == 2)
		dcp->h = va_arg(*ap, unsigned long long int);
	else if (dcp->flags[6] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->i = (unsigned short int)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[7] == 2)
		dcp->j = va_arg(*ap, unsigned long int);
	else
		dcp->f = va_arg(*ap, unsigned int);
	if (min_else(dcp) == 0)
		return (ft_convertbase_u(max_else(dcp), 16, 0, dcp->precision));
	else
		return (ft_convertbase_u(min_else(dcp), 16, 0, dcp->precision));
}

char	*ft_capx(t_list *dcp, va_list *ap)
{
	if (dcp->flags[8] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->g = (unsigned char)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[9] == 2)
		dcp->h = va_arg(*ap, unsigned long long int);
	else if (dcp->flags[6] == 2)
	{
		dcp->a = va_arg(*ap, int);
		dcp->i = (unsigned short int)dcp->a;
		dcp->a = 0;
	}
	else if (dcp->flags[7] == 2)
		dcp->j = va_arg(*ap, unsigned long int);
	else
		dcp->f = va_arg(*ap, unsigned int);
	if (min_else(dcp) >= 0)
		return (ft_convertbase_u(max_else(dcp), 16, 1, dcp->precision));
	else
		return (ft_convertbase_u(min_else(dcp), 16, 1, dcp->precision));
}

char	*ft_p(t_list *dcp, va_list *ap)
{
	void	*p;

	p = va_arg(*ap, void*);
	return (ft_convertbase((long)p, 16, 0, dcp->precision));
}
