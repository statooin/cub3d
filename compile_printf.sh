rm *.o
rm runme
make
gcc -o runme -Wall -Wextra -Werror -g -O0 main28_1.c libftprintf.a
rm *.o
./runme
