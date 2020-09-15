/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:28:49 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 17:49:18 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CUB_H
# define READ_CUB_H

# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../cub3d.h"

typedef struct	s_param
{
	int			iscreen_width;
	int			iscreen_height;
	int			col_floor;
	int			col_ceiling;
}				t_param;

typedef struct	s_check
{
	int		found_r;
	int		found_no;
	int		found_so;
	int		found_we;
	int		found_ea;
	int		found_s;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*path_s;
	int		found_f;
	int		found_c;
	int		map_lines; // number of map lines with extra lines in the end
	int		count_lines; // lines before map;
}				t_check;

int		ft_cub_validation(void);
//int	ft_cub_validation(t_game *g_game);
void	ft_init_structs(t_check *checks, t_param *param);
size_t	ft_strlcpy_set_ch(char *dst, const char *src, size_t size, char x);
void	ft_skip_spaces(char *line, int *i);
void	ft_skip_spaces_n_comma(char *line, int *i);
int		ft_search_r(t_check *checks, t_param *param, char *line);
int		ft_search_no(t_check *checks, char *line);
int		ft_search_so(t_check *checks, char *line);
int		ft_search_we(t_check *checks, char *line);
int		ft_search_ea(t_check *checks, char *line);
int		ft_search_s(t_check *checks, char *line);
int		ft_search_f(t_check *checks, t_param *param, char *line);
int		ft_search_c(t_check *checks, t_param *param, char *line);
int		ft_longest_mapline(t_check *checks);
int		ft_map_borders(char **map, t_check *checks);
int		ft_forbid_symbols(char **map);
int		ft_map_w_spaces(int line_len, t_check *checks);
int		ft_map(char *line, t_check *checks);
int		ft_check_if_all_found(t_check *cheks);
int		ft_search_map(t_check *checks);
int		ft_what_type(t_check *checks, t_param *param);
int	ft_valid_resolution(int *width, int *height);

#endif
