HEADER = test.h

NAME = push_swap

B_NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC	=	main.c parssing.c markup.c push_b.c actions.c actions2.c push_a.c parssing_2.c push_a_2b.c push_a_2.c sort_3_5.c ./libft_p/ft_atoi.c ./libft_p/ft_calloc.c ./libft_p/ft_isalpha.c ./libft_p/ft_isdigit.c ./libft_p/ft_lstadd_back.c ./libft_p/ft_lstadd_front.c ./libft_p/ft_lstclear.c ./libft_p/ft_lstdelone.c ./libft_p/ft_lstlast.c ./libft_p/ft_lstnew.c ./libft_p/ft_lstsize.c ./libft_p/ft_split.c ./libft_p/ft_strchr.c ./libft_p/ft_strdup.c ./libft_p/ft_strjoin.c ./libft_p/ft_strlen.c ./libft_p/ft_strncmp.c ./libft_p/ft_substr.c ./libft_p/ft_bzero.c ./libft_p/ft_memset.c

SRCS_BNS = 	checker.c parssing.c markup.c push_b.c actions.c actions2.c push_a.c ./libft_p/ft_atoi.c ./libft_p/ft_calloc.c ./libft_p/ft_isalpha.c ./libft_p/ft_isdigit.c ./libft_p/ft_lstadd_back.c ./libft_p/ft_lstadd_front.c ./libft_p/ft_lstclear.c ./libft_p/ft_lstdelone.c ./libft_p/ft_lstlast.c ./libft_p/ft_lstnew.c ./libft_p/ft_lstsize.c ./libft_p/ft_split.c ./libft_p/ft_strchr.c ./libft_p/ft_strdup.c ./libft_p/ft_strjoin.c ./libft_p/ft_strlen.c ./libft_p/ft_strncmp.c ./libft_p/ft_substr.c ./libft_p/ft_bzero.c ./libft_p/ft_memset.c push_a_2.c parssing_2.c push_a_2b.c actions2_b.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJ =	${SRC:.c=.o}

bonus_OBJ = ${SRCS_BNS:.c=.o}

RM	=	rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	 	@${CC} ${CFLAGS} ${SRC} -o ${NAME}

%.o:%.c test.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : ${bonus_OBJ}
		@${CC} ${CFLAGS} ${bonus_OBJ} -o ${B_NAME}

clean :
	@${RM} ${OBJ} ${bonus_OBJ}

fclean :
		@${RM} ${OBJ} ${bonus_OBJ} ${NAME} ${B_NAME}

re : fclean all

re_bonus : fclean bonus
