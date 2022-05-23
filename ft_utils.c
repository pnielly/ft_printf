/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:44:02 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/13 18:35:02 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_sign(long nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\v' ||
				str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(str[i]);
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

void			*ft_bzero(void *s, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (n > 0 && s)
	{
		*c = 0;
		c++;
		n--;
	}
	return (0);
}

int				ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0 && ptr)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}
