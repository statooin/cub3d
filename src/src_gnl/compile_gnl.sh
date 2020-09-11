rm *.o
rm runme
gcc -Wall -Wextra -Werror -g -O0 ft_check_if_all_found.c ft_forbid_symbols.c ft_init_structs.c ft_longest_mapline.c ft_map.c ft_map_borders.c ft_map_w_spaces.c ft_search_c.c ft_search_ea.c ft_search_f.c ft_search_map.c ft_search_no.c ft_search_r.c ft_search_s.c ft_search_so.c ft_search_we.c ft_skip_spaces.c ft_skip_spaces_n_comma.c ft_strlcpy_set_ch.c ft_what_type.c main.c gnl/get_next_line.c gnl/get_next_line_utils.c ../../libft/libft.a -o runme
#gcc -c -Wall -Wextra -Werror -g -O0 *.c libft.a
#gcc -o runme *.o
rm *.o
./runme
