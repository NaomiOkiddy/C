/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:16:47 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:16:48 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *join;
	char *temp;

	if (!s1 || !s2 ||
	((temp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)) == 0))
		return (NULL);
	join = temp;
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (join);
}
