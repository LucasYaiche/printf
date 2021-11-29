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
					@gcc ${CFLAGS} -c $< -o ${<:.c=.o}
					@printf "\e[32;3m.\e[0m"
					

all:				${NAME}

${NAME}:			${OBJS_LIBFT} ${OBJS_PRINTF}
					@${AR} ${NAME} ${OBJS_LIBFT} ${OBJS_PRINTF}
					@ranlib ${NAME}
					@printf "\n\e[32;3m$@ successfully build\e[0m\n"
			

clean:
					@rm -f ${OBJS_LIBFT} ${OBJS_PRINTF}
					@printf "\e[31;3mClean files\e[0m\n"

fclean:				clean
					@rm -f ${NAME}
					@printf "\e[31;3mClean exec\e[0m\n"

re:					fclean all

test:				re
					@gcc ${CFLAGS} libftprintf.a ft_printf.c && ./a.out


.PHONY:		all clean fclean re test

