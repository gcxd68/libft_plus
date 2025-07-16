# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 10:34:21 by gdosch            #+#    #+#              #
#    Updated: 2025/06/25 17:40:18 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_arrlen.c \
			ft_atoi.c \
			ft_atoi_base.c \
			ft_atol.c \
			ft_atoll.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_dprintf.c \
			ft_dynarr_add_char.c \
			ft_dynarr_add_int.c \
			ft_dynarr_add_ptr.c \
			ft_dynarr_free.c \
			ft_dynarr_from.c \
			ft_dynarr_init.c \
			ft_dynarr_remove.c \
			ft_free_arr.c \
			ft_free_int_arr.c \
			ft_int_arr_get.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_is_valid_filename.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_rand.c \
			ft_realloc.c \
			ft_snprintf.c \
			ft_split.c \
			ft_sprintf.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_stricmp.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_ternary.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_vdprintf.c \
			ft_vprintf.c \
			ft_vsnprintf.c \
			ft_vsprintf.c \
			get_next_line.c \
			safe_gnl.c

OBJ =		$(SRC:.c=.o)

NAME =		libft.a
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar -rcs $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re