# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: statooin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/24 13:10:03 by statooin          #+#    #+#              #
#    Updated: 2020/05/26 09:39:43 by statooin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

INCLUDES = $(NAME:.a=.h)

LIBFTSRC := ft_absneg.c \
	ft_abspos.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_iswhitespace.c \
	ft_itoa_base.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstaddback.c \
	ft_lstadd.c \
	ft_lstadd_front.c \
	ft_lstaddnext.c \
	ft_lstclear.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstlen.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memcdup.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memdelsize.c \
	ft_memdup.c \
	ft_memexpand.c \
	ft_memjoin.c \
	ft_memmove.c \
	ft_memrcpy.c \
	ft_memset.c \
	ft_nbrlenbase.c \
	ft_nbrlenbase_ull.c \
	ft_nbrlen.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_slltoa_base.c \
	ft_split.c \
	ft_strcat.c \
	ft_strcharexpand.c \
	ft_strcharjoin.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strexpand.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin_f.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strlenc.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnewfill.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_swap.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_ulltoa_base_low.c \
	ft_ulltoa_base_upp.c

OBJ = 	$(LIBFTSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;194m
C_FCLEAN = \033[38;5;156m
C_GREEN = \033[38;5;34m
C_TEST = \033[38;5;28m
C_YELLOW = \033[38;5;220m
C_LINES = \033[38;5;250m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	ar -rcs $@ $?
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@echo "$(C_GREEN)$(NAME)  has been compiled$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"

%.o: %.c $(INCLUDES)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(C_YELLOW)$@ compiled$(C_RESET)"

so:
	gcc -fPIC -c $(LIBFTSRC)
	gcc -shared -o libft.so $(OBJ)

clean:
	rm -rf $(OBJ)
	@echo "-----------------"
	@echo "$(C_FCLEAN)Object files deleted$(C_RESET)"
	@echo "-----------------"

fclean:	clean
	rm -rf $(NAME)
	rm -rf libft.so
	@echo "-----------------"
	@echo "$(C_FCLEAN)$(NAME) deleted$(C_RESET)"
	@echo "-----------------"

re: fclean all
