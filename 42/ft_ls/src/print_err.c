/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:19:55 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 14:19:56 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir_error(char *dirname)
{
	ft_putstr("ls: ");
	ft_putstr(dirname);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
}

void		print_flag_err(char flag)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ls [-lRart] [file ...]\n");
	exit(1);
}
