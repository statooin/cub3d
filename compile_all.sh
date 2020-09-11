rm *.o
rm runme
gcc -Wall -Wextra -Werror -g -O0 *.c *.h minilibx/libmlx.a libft/libft.h libft/*.c src/src_gnl/*.c src/src_gnl/read_cub.h src/src_gnl/gnl/get_next_line.h src/src_gnl/gnl/*.c -o runme -lm -L/usr/X11/lib -lXext -lX11
#gcc -c -Wall -Wextra -Werror -g -O0 *.c libft.a
#gcc -o runme *.o
rm *.o
./runme
