rm *.o
rm runme
gcc -Wall -Wextra -Werror -g -O0 *.c cub3D.h minilibx/libmlx.a libft/libft.a -o runme -lm -L/usr/X11/lib -lXext -lX11
#gcc -c -Wall -Wextra -Werror -g -O0 *.c libft.a
#gcc -o runme *.o
rm *.o
./runme
