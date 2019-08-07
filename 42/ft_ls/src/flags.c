/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:17:09 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/03 18:17:31 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long int		check_flags(char *flags)
{
	long int	flags_num;
	int			i;

	flags_num = 0x0;
	i = 0;
	while (flags[++i])
	{
		if (flags[i] == '-')
			i++;
		if (flags[i] == 'l')
			flags_num |= ls_flag_l;
		else if (flags[i] == 'a')
			flags_num |= ls_flag_a;
		else if (flags[i] == 'r')
			flags_num |= ls_flag_r;
		else if (flags[i] == 't')
			flags_num |= ls_flag_t;
		else if (flags[i] == 'R')
			flags_num |= ls_flag_R;
		else
			print_flag_err(flags[i]);
	}
	return (flags_num);
}

int				count_flags(long int *temp_flags, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' &&
		ft_strcmp(argv[i], "-") != 0)
	{
		*temp_flags += check_flags(argv[i]);
		i++;
	}
	return (i);
}
