NAME = pathfinder

INC = ./path.h ./libmx.h

INCI = ./inc/path.h ./inc/libmx.h

SRC = ./main.c \
./mx_printerror.c \
./mx_deldub.c \
./mx_arr_to_list.c \
./mx_pathfinder.c \
./mx_creat_MX.c \
./mx_fill_path.c \
./mx_adjacency.c \
./mx_deep_search.c \
./mx_stack.c \
./mx_del_first_stack.c \
./mx_arr_to_str.c

SRCS = ./src/main.c \
./src/mx_printerror.c \
./src/mx_deldub.c \
./src/mx_arr_to_list.c \
./src/mx_pathfinder.c \
./src/mx_creat_MX.c \
./src/mx_fill_path.c \
./src/mx_adjacency.c \
./src/mx_deep_search.c \
./src/mx_stack.c \
./src/mx_del_first_stack.c \
./src/mx_arr_to_str.c

OBJ = ./main.o \
./mx_printerror.o \
./mx_deldub.o \
./mx_arr_to_list.o \
./mx_pathfinder.o \
./mx_creat_MX.o \
./mx_fill_path.o \
./mx_adjacency.o \
./mx_deep_search.o \
./mx_stack.o \
./mx_del_first_stack.o \
./mx_arr_to_str.o

LOBJ = ./mx_printchar.o \
./mx_atoi.o \
./mx_print_unicode.o \
./mx_printstr.o \
./mx_print_strarr.o \
./mx_printint.o \
./mx_pow.o \
./mx_sqrt.o \
./mx_nbr_to_hex.o \
./mx_hex_to_nbr.o \
./mx_itoa.o \
./mx_foreach.o \
./mx_binary_search.o \
./mx_bubble_sort.o \
./mx_quicksort.o \
\
./mx_strlen.o \
./mx_swap_char.o \
./mx_str_reverse.o \
./mx_strdel.o \
./mx_del_strarr.o \
./mx_get_char_index.o \
./mx_strdup.o \
./mx_strndup.o \
./mx_strcpy.o \
./mx_strncpy.o \
./mx_strcmp.o \
./mx_strcat.o \
./mx_strstr.o \
./mx_get_substr_index.o \
./mx_count_substr.o \
./mx_count_words.o \
./mx_strnew.o \
./mx_strtrim.o \
./mx_del_extra_spaces.o \
./mx_strsplit.o \
./mx_strjoin.o \
./mx_file_to_str.o \
./mx_read_line.o \
./mx_replace_substr.o \
\
./mx_memset.o \
./mx_memcpy.o \
./mx_memccpy.o \
./mx_memcmp.o \
./mx_memchr.o \
./mx_memrchr.o \
./mx_memmem.o \
./mx_memmove.o \
./mx_realloc.o \
\
./mx_create_node.o \
./mx_pop_back.o \
./mx_pop_front.o \
./mx_push_back.o \
./mx_push_front.o \
./mx_list_size.o \
./mx_sort_list.o \
\
./mx_isspace.o \
./mx_isdigit.o \
./mx_isalpha.o \
./mx_swap_str.o \
./mx_strlen_my.o


CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make install -sC libmx/
	@cp libmx/libmx.a $(INCI) $(SRCS) .
	@ar x libmx.a
	@clang $(CFLGS) -c  $(SRC) -I $(INC)
	@clang $(CFLGS) $(OBJ) $(LOBJ) -o $(NAME)
	@mkdir  obj
	@mv $(OBJ) $(LOBJ) ./obj
	@rm -rf $(SRC) $(INC) 
	@rm -rf libmx.a __.SYMDEF\ SORTED libmx.h.gch
	
uninstall: clean
	@make uninstall -sC libmx/
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx/
	@rm -rf ./obj

reinstall: uninstall install
