/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:47:52 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/03 13:18:31 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_len(int n)
{
	int		i;
	int		m;

	i = 0;
	m = n;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (m < 0)
		i++;
	return (i);
}

char		*ft_build_str(int n, char *str, int len)
{
	long	v;
	int		k;

	if (n == 0)
	{
		str[0] = 48;
	}
	v = (long)n;
	if (v < 0)
	{
		str[0] = '-';
		v = -v;
	}
	str[len] = '\0';
	if (v != 0)
	{
		k = (1 - (n / v)) / 2;
		while (len > k)
		{
			str[--len] = v % 10 + 48;
			v = v / 10;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	if (!(str = malloc(len + 1)))
		return (0);
	return (ft_build_str(n, str, len));
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*d1;

	if (!src && !dst)
		return (0);
	s1 = src;
	d1 = dst;
	if (!n)
		return (dst);
	while (n-- > 0)
		*d1++ = *s1++;
	return (dst);
}

size_t		ft_strlcpy(char *dst,
		const char *src, size_t dstsize)
{
	unsigned char	srclen;

	if (!src && !dst)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize] = '\0';
	}
	return (srclen);
}
