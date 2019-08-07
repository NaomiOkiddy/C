/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:28:15 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:34:23 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long	ft_numlen(long long num)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int			ft_max(int num1, int num2)
{
	if (num1 >= num2)
		return (num1);
	return (num2);
}

void		ft_putspace(int num_space)
{
	while (num_space-- > 0)
		ft_putchar(' ');
}

void		right_justify(int num, size_t min_len)
{
	size_t len;

	len = ft_numlen(num);
	if (len < min_len)
		ft_putspace(min_len - len);
	ft_putnbr(num);
}

void		left_justify(int num, size_t min_len)
{
	size_t len;

	len = ft_numlen(num);
	ft_putnbr(num);
	if (len < min_len)
		ft_putspace(min_len - len);
}
