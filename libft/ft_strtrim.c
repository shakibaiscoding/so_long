/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:41 by saghighi          #+#    #+#             */
/*   Updated: 2024/10/31 12:03:42 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen (s1);
	str = 0;
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr (set, s1[i]))
		{
			i++;
		}
		while (s1[j - 1] && ft_strchr (set, s1[j - 1]) && j > i)
		{
			j--;
		}
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
		{
			ft_strlcpy(str, &s1[i], j - i + 1);
		}
	}
	return (str);
}
