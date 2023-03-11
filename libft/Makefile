# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Make                                               :+:    :+:             #
#                                                      +:+                     #
#    By: bmajor <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/31 08:05:47 by bmajor        #+#    #+#                  #
#    Updated: 2022/06/07 15:06:50 by bmajor        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS_FILES		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
					ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
					ft_isalpha.c ft_atoi.c ft_putendl_fd.c ft_strchr.c \
					ft_itoa.c ft_memcpy.c ft_strlcpy.c ft_strnstr.c \
					ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
					ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_strrchr.c ft_memset.c ft_itoa_base.c ft_digit_count.c \
					ft_split_whitespace.c ft_lst_add_back_double.c ft_strncpy.c ft_is_n_in_str.c \
					ft_free_str.c

SRCS			=	$(addprefix $(DIR)/, $(SRCS_FILES))
OBJS			=	$(SRCS:.c=.o)
HEADERS_DIR		=	headers
HEADER_FILE		=	libft.h
DIR				=	sources

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		=	$(BONUS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I.
ARCHIVE			=	ar rcs

ifdef WITH_BONUS
OBJ_FILES		= $(OBJS) $(BONUS_OBJS)
else
OBJ_FILES		= $(OBJS)
endif

all:			$(NAME)

$(NAME):		$(OBJ_FILES)
				@$(ARCHIVE) $(NAME) $(OBJ_FILES)

%.o:			%.c $(addprefix $(HEADERS_DIR)/, $(HEADER_FILE))
				@$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADERS_DIR)

bonus:
				@$(MAKE) WITH_BONUS=1 all
clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:
					@$(MAKE) fclean
					@$(MAKE) all

.PHONY:			all clean fclean re bonus
