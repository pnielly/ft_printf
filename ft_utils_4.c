/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:32:50 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/13 17:49:20 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}

char	*ft_strrchr(const char *s, int c, int stop)
{
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == c)
		return ((char *)s);
	while (s[i] != stop)
		i++;
	while (i)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i--;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char*)malloc(sizeof(char) * i + sizeof(char) * j + 1)))
		return (0);
	while (++k < i)
		str[k] = s1[k];
	while (k < i + j)
	{
		str[k] = s2[k - i];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] != needle[0] && haystack[i] != '\0' && i < len)
			i++;
		while (haystack[i] == needle[j] && j < len && i < len && needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' || j == len)
		{
			haystack = &haystack[i - j];
			return ((char*)haystack);
		}
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	j = start;
	while (len-- > 0 && s[j] != '\0')
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
