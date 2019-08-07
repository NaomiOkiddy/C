/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:34:10 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:34:18 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		right_justify_string(char *str, size_t min_len)
{
	size_t len;

	len = ft_strlen(str);
	if (len < min_len)
		ft_putspace(min_len - len);
	ft_putstr(str);
}

void		left_justify_string(char *str, size_t min_len)
{
	size_t len;

	len = ft_strlen(str);
	ft_putstr(str);
	if (len < min_len)
		ft_putspace(min_len - len);
}

void		right_justify_char(char c, size_t min_len)
{
	if (1 < min_len)
		ft_putspace(min_len - 1);
	ft_putchar(c);
}

void		left_justify_char(char c, size_t min_len)
{
	ft_putchar(c);
	if (1 < min_len)
		ft_putspace(min_len - 1);
}

void		string_precision(char *str, size_t precision)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] && i < precision)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
