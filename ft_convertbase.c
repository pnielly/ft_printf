/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:30:00 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 17:30:04 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_letter(long l, int size)
{
	char	*tab;
	char	*tab_x;
	char	*tab_capx;
	int		i;

	i = -1;
	tab = "\12\13\14\15\16\17";
	tab_x = "\141\142\143\144\145\146";
	tab_capx = "\101\102\103\104\105\106";
	while (i++ < 5)
	{
		if (l == tab[i])
		{
			if (size)
				return (tab_capx[i]);
			else
				return (tab_x[i]);
		}
	}
	return (0);
}

char	*ft_build(long long nb, int base, int size, int i)
{
	long	nb2;
	char	*str;
	int		sign;

	sign = ft_sign(nb);
	nb = nb * sign;
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (nb)
	{
		nb2 = nb % base;
		if (nb2 <= 9)
			str[i] = nb % base + '0';
		if (nb2 > 9)
			str[i] = ft_letter(nb2, size);
		nb = nb / base;
		i--;
	}
	if (sign < 0)
		str[0] = '-';
	free(str);
	return (str);
}

char	*ft_convertbase(long long nb, int base, int size, int precision)
{
	int			i;
	long long	nb2;
	int			sign;

	if (precision == 0 && nb == 0)
		return ("");
	i = 0;
	if (nb == 0)
		return ("0");
	if (nb < 0)
	{
		sign = -1;
		i = 1;
	}
	nb2 = nb;
	while (nb2)
	{
		nb2 = nb2 / base;
		i++;
	}
	return (ft_build(nb, base, size, i));
}

char	*ft_build_u(unsigned int nb, int base, int size, int i)
{
	unsigned int	nb2;
	char			*str;

	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (nb)
	{
		nb2 = nb % base;
		if (nb2 <= 9)
			str[i] = nb % base + '0';
		if (nb2 > 9)
			str[i] = ft_letter(nb2, size);
		nb = nb / base;
		i--;
	}
	free(str);
	return (str);
}

char	*ft_convertbase_u(unsigned int nb, int base, int size, int precision)
{
	int				i;
	unsigned int	nb2;

	if (precision == 0 && nb == 0)
		return ("");
	i = 0;
	if (nb == 0)
		return ("0");
	nb2 = nb;
	while (nb2)
	{
		nb2 = nb2 / base;
		i++;
	}
	return (ft_build_u(nb, base, size, i));
}
