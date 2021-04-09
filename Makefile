SHELL =		/bin/sh
.SUFFIXES =	.c .h .o

NAME =		

SRCD =		src
INCD =		inc
OBJD =		.obj
LIBD =		lib

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			)
INC =		$(addsuffix $(word 2, $(.SUFFIXES)),\
			)
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 3, $(.SUFFIXES)))
LIB =		

CC =		gcc
CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCD)
LIBCFLAGS =	$(addprefix -L, $(LIBD))\
			$(addprefix -l, $(LIB))

COUNT =		$(shell cat file.count 2>/dev/null)

ifeq ($(COUNT),)
all:
	@echo $(words $(SRC)) > file.count
	@$(MAKE) -n | grep $(CC) | wc -l | tr -d ' ' > tmp.txt
	@rm -f file.count
	@echo $$(($$(cat tmp.txt) - 1)) > file.count
	@rm -f tmp.txt
	@./make/remake.sh
else
all: $(NAME)
endif

$(NAME): $(addprefix $(OBJD)/, $(OBJ)) | $(addprefix $(INCD)/, $(INC))
	@rm -f file.count
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBCFLAGS)
	@printf "\r\033[2KCompiling [\033[32mOK\033[0m]\n"

$(OBJD):
	@mkdir $@

$(OBJD)/%$(word 3, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) | $(OBJD)
	@./make/prc.sh 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all
