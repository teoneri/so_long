/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:38:52 by mneri             #+#    #+#             */
/*   Updated: 2022/10/10 11:38:53 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char *str1, const char *set, int i, int l)
{
	while (set[l] != '\0')
	{
		if (str1[i] == set[l])
		{
			i++;
			l = 0;
		}
		else
			l++;
	}
	return (i);
}

static int	finish(char *str1, const char *set, int l, int j)
{
	j = ft_strlen((char *)str1);
	l = 0;
	while (set[l] != '\0')
	{
		if (str1[j - 1] == set[l])
		{
			j--;
			l = 0;
		}
		else
			l++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*str1;
	int		i;
	int		j;
	int		k;

	str1 = (char *)s1;
	k = 0;
	i = 0;
	j = ft_strlen((char *)s1);
	trim = malloc(sizeof(char) * (j + 1));
	if (!trim)
		return (NULL);
	i = start(str1, set, i, 0);
	j = finish(str1, set, j, 0);
	while (i < j)
	{
		trim[k] = str1[i];
		i++;
		k++;
	}
	trim[k] = '\0';
	return (trim);
}
