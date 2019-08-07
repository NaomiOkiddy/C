/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:51:17 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 15:51:18 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_nlink(int nlink, int padding)
{
	ft_putchar(' ');
	if (padding)
		right_justify(nlink, padding);
	else
		ft_putnbr(nlink);
	ft_putchar(' ');
}

void	print_size(int size, int padding)
{
	if (padding)
		right_justify(size, padding);
	else
		ft_putnbr(size);
}
