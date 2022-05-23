/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:36 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 15:35:42 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	max_di(t_list *dcp)
{
	long long int	a;
	long long int	b;

	if ((long long int)dcp->b > (long long int)dcp->c)
		a = (long long int)dcp->b;
	else
		a = (long long int)dcp->c;
	if ((long long int)dcp->d > (long long int)dcp->e)
		b = (long long int)dcp->d;
	else
		b = (long long int)dcp->e;
	if (a > b)
		b = a;
	else if ((long long int)dcp->a > b)
		b = (long long int)dcp->a;
	return (b);
}

int	max_else(t_list *dcp)
{
	long long int	a;
	long long int	b;

	if ((long long int)dcp->g > (long long int)dcp->h)
		a = (long long int)dcp->g;
	else
		a = (long long int)dcp->h;
	if ((long long int)dcp->i > (long long int)dcp->j)
		b = (long long int)dcp->i;
	else
		b = (long long int)dcp->j;
	if (a > b)
		b = a;
	else if ((long long int)dcp->f > b)
		b = (long long int)dcp->f;
	return (b);
}

int	min_di(t_list *dcp)
{
	long long int	a;
	long long int	b;

	if ((long long int)dcp->b < (long long int)dcp->c)
		a = (long long int)dcp->b;
	else
		a = (long long int)dcp->c;
	if ((long long int)dcp->d < (long long int)dcp->e)
		b = (long long int)dcp->d;
	else
		b = (long long int)dcp->e;
	if (a < b)
		b = a;
	else if ((long long int)dcp->a < b)
		b = (long long int)dcp->a;
	return (b);
}

int	min_else(t_list *dcp)
{
	long long int	a;
	long long int	b;

	if ((long long int)dcp->g < (long long int)dcp->h)
		a = (long long int)dcp->g;
	else
		a = (long long int)dcp->h;
	if ((long long int)dcp->i < (long long int)dcp->j)
		b = (long long int)dcp->i;
	else
		b = (long long int)dcp->j;
	if (a < b)
		b = a;
	else if ((long long int)dcp->f < b)
		b = (long long int)dcp->f;
	return (b);
}

int	max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}
