#===================================#
#[LIBFT] Fonctions partie principale#
#===================================#

SRC_LIBFT =ft_putchar.c ft_putnbr_unsigned.c \
ft_putstr.c ft_putnbr.c ft_puthexa.c


OBJS_LIBFT = ${SRC_LIBFT:.c=.o}

#===================================#
#[PRINTF] Fonction partie principale#
#===================================#

SRC_PRINTF = ft_printf.c

OBJS_PRINTF = ${SRC_PRINTF:.c=.o}

#====#
#Tags#
#====#

NAME = libftprintf.a
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

#=========#
#Commandes#
#=========#
.c.o:
					gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:				${NAME}

${NAME}:			${OBJS_LIBFT} ${OBJS_PRINTF}
					${AR} ${NAME} ${OBJS_LIBFT} ${OBJS_PRINTF}
					ranlib ${NAME}
			

clean:
					rm -f ${OBJS_LIBFT} ${OBJS_PRINTF}

fclean:				clean
					rm -f ${NAME}

re:					fclean all

test:				
					gcc ${CFLAGS} libftprintf.a ft_printf.c && ./a.out


.PHONY:		all clean fclean re test

