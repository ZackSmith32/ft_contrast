# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/04/09 11:06:12 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_contrast
FLAGS	=	-c -Wall -Wextra -Werror
FSAN	=	#-fsanitize=address -g
CFILES	=	ft_contrast.c
			
			# test_mallocwrap.c	\

LIBS	=	libft/libft.a			\
			
SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
LIBDIR  =	libdir/
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))
LIBFILES=	$(addprefix $(LIBDIR), $(LIBS))

.PHONY: all $(NAME) clean flcean re

all: libs $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	gcc  $(FLAGS) $< -o $@ $(FSAN)

$(NAME): $(OFILES)
	gcc $(FSAN) $(OFILES) -o $@ -I $(HDIR) -L. $(LIBFILES)
	
libs:
	make -C libdir/libft

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libdir/libft

re: fclean all
