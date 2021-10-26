#===================================#
#[LIBFT] Fonctions partie principale#
#===================================#

SRC_LIBFT = ft_isalpha.c ft_memcmp.c  ft_strchr.c  ft_strlen.c  ft_substr.c \
ft_atoi.c    ft_isascii.c ft_memcpy.c  ft_strdup.c  ft_strncmp.c ft_tolower.c \
ft_bzero.c   ft_isdigit.c ft_memmove.c ft_strjoin.c ft_strnstr.c ft_toupper.c \
ft_calloc.c  ft_isprint.c ft_memset.c  ft_strlcat.c ft_strrchr.c ft_isalnum.c ft_memchr.c \
ft_strlcpy.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstdelone.c

PRE_SRC_LIBFT = ${addprefix ${PRE}, ${SRC_LIBFT}}

OBJS_LIBFT = ${PRE_SRC_LIBFT:.c=.o}

#==============================#
#[LIBFT] Fonctions partie bonus#
#==============================#

BONUS_LIBFT = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRE_BONUS_LIBFT = ${addprefix ${PRE}, ${BONUS_LIBFT}}

OBJS_BONUS_LIBFT = ${PRE_BONUS_LIBFT:.c=.o}

#===================================#
#[PRINTF] Fonction partie principale#
#===================================#

SRC_PRINTF = ft_printf.c

OBJS_PRINTF = ${SRC_PRINTF:.c=.o}

#====#
#Tags#
#====#

PRE = ./Libft/
NAME = libft.a
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

#=========#
#Commandes#
#=========#
.c.o:
					gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:				${NAME}

${NAME}:			${OBJS_LIBFT}
					${AR} ${NAME} ${OBJS_LIBFT}
					ranlib ${NAME}
			
printf_bonus:		${OBJS_LIBFT} ${OBJS_BONUS_LIBFT}
					${AR} ${NAME} ${OBJS_LIBFT} ${OBJS_BONUS_LIBFT}
					ranlib ${NAME}

clean:
					rm -f ${OBJS_LIBFT} ${OBJS_BONUS_LIBFT}

fclean:				clean
					rm -f ${NAME}

re:					fclean all



everything:	all bonus

.PHONY:		all clean fclean re bonus everything

