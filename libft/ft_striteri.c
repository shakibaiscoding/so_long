/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:16 by saghighi          #+#    #+#             */
/*   Updated: 2024/10/29 10:57:30 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
