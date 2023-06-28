CC =gcc
CFLAGS =-I/usr/include -g 
LDFLAGS = 
EXEC =minishell

INCLUDES = -I ./Libft/Libft -I ./Libft/List -I ./Libft -I Libft/files/ -I ./lem_list

SRC = ./Libft/Libft/libft.c \
		./Libft/Libft/ft_strsjoin.c \
		./Libft/List/list.c \
		./Libft/ft_printf.c \
		./Libft/files/file.c \
		./Libft/get_next_line.c \
		./lem_list/lem_list.c \
		./lem-in.c

HEADS = ./Libft/Libft/libft.h \
		./Libft/List/list.h \
		./Libft/files/file.h \
		./lem_list/lem_list.h 

		
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC) 

$(OBJ) : $(HEADS)

%.o :%.c  $(HEADS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	

.PHONY: all clean mrproper builtins

clean : 
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXEC)
	sudo rm -rf /usr/share/minishell

builtins: all
	sudo mkdir /usr/share/minishell/
	sudo cp ./var/env  /usr/share/minishell/
	sudo cp ./draws/draws.txt /usr/share/minishell
	sudo chmod -R a+rwX /usr/share/minishell
	


	




