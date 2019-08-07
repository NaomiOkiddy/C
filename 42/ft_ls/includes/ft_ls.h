/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:58:56 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/27 12:58:57 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define STRING_MAX 1056
# define NULL_CHECK(x)	if (x) { return ;}

typedef struct			s_file
{
	char				*name;
	char				*filepath;
	struct stat			buf;
	struct s_file		*next;
	struct timespec		cmptime;
}						t_file;

typedef struct			s_directory
{
	char				*dirname;
	long int			flags;
	int					file_count;
	struct s_file		*first_file;
	struct s_directory	*next;
}						t_directory;

enum					e_flags
{
	ls_flag_l = 0x00001,
	ls_flag_a = 0x00010,
	ls_flag_r = 0x00100,
	ls_flag_t = 0x01000,
	ls_flag_R = 0x10000,
	ls_flag_cur = 0x100000
};

void					parse_command(int argc, char **argv);
long int				check_flags(char *flags);
int						count_flags(
	long int *temp_flags, char **argv, int argc);
t_directory				*recursive_dir(
	int argc, char **argv, int count, long int flags);
void					get_directory(
	t_directory **tmp, char *path, long int flags);
void					add_directory(
	t_directory **list, char *dirname, long int flags);
void					choose_sort(t_directory **begin_list, long int flags);
void					sort_directory(t_directory **begin_list, int (*cmp)());
void					swap_directory(t_directory **a, t_directory **b);
int						count_directory(t_directory **dir);
void					open_directory(t_directory **list, int num_directory);
void					remove_directory(t_directory **list);
int						check_exists(char *pathname);
void					deal_with_strays(t_directory **list);
void					still_dealing_with_strays(
	t_directory **temp, t_directory **strays);
int						check_directory(char *pathname);
void					act_on_strays(t_directory *strays);
void					reverse_sort_directory(t_directory **begin_list);
int						get_files(DIR *directory, t_directory *dir);
void					add_files(t_directory *dir, char *dirname, char *name);
int						sorting(t_directory *dir);
void					sort_file(t_directory *dir, int (*cmp)());
void					swap_file(t_file **a, t_file **b);
void					reverse_sort_file(t_directory *dir);
int						time_cmp(const char *path1, const char *path2);
void					print_file_details(t_file *a, int *padding);
void					print_file_name(
	t_file *a, long int print_flags, int *padding);
void					print_dirname(char *dirname, long int flags);
void					print_bloc_size(int size);
void					print_file(t_directory *dir);
void					print_type(mode_t permissions);
void					print_permissions(mode_t permissions);
void					print_link(t_file *a);
void					print_xattr(char *pathname);
void					print_date(struct stat *stat);
void					print_nlink(int nlink, int padding);
void					print_size(int size, int padding);
void					print_dir_error(char *dirname);
void					print_flag_err(char flag);
void					get_pathname(char *pathname, const char *filepath,
const char *name);
int						get_bloc_size(t_directory *dir);
void					get_padding(t_directory *dir, int *padding);
long long				ft_numlen(long long num);
int						ft_max(int num1, int num2);
void					ft_putspace(int num_space);
void					right_justify(int num, size_t min_len);
void					left_justify(int num, size_t min_len);
void					right_justify_string(char *str, size_t min_len);
void					left_justify_string(char *str, size_t min_len);
void					right_justify_char(char c, size_t min_len);
void					left_justify_char(char c, size_t min_len);
void					string_precision(char *str, size_t precision);
void					delete_dir(t_directory **dir);
void					delete_files(t_file **fil);

#endif
