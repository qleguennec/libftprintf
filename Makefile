# Directories
PROJECT		=	libftprintf
BINDIR		?=	.
SRCDIR		?=	src
BUILDDIR	?=	build
LIBDIR		?=	$(BUILDDIR)
DEPSDIR		?=	lib
INCLUDE		+=	includes
NAME		=	libftprintf.a
TARGET		=	$(BINDIR)/$(NAME)

# Compiler options
CC			=	clang
LIBFLAGS	=	$(subst lib,-l,$(LIBSRC))
CFLAGS		=	$(addprefix -I,$(INCLUDE)) -Wall -Wextra -Werror -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

# Source files
include src.mk

# Libraries
LIBSRC		=	libbst libft

OBJECTS		+=	$(foreach lib, $(LIBSRC), $(addprefix $(DEPSDIR)/$(lib)/, $(shell make -s -C $(DEPSDIR)/$(lib) get-OBJECTS)))
OBJECTS		+=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))

all:				deps $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR); true
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)+++ obj:'\t'$(END)$(BUILDDIR)/$(YELLOW)'\t'$(@F)$(END)

$(DEPSDIR)/%.o:
	@INCLUDE=$(CURDIR)/$(INCLUDE) \
		make -s -C $(@D:%/build=% build/$(@F)) > /dev/null
	@echo $(GREEN)+++ obj:'\t'$(END)$(@D)/$(YELLOW)'\t'$(@F)$(END)

$(TARGET): $(OBJECTS)
	@ar rc $(@) $(OBJECTS)
	@echo $(GREEN)+++ target:'\t'$(END)./'\t'$(BLUE)$(NAME)$(END)

$(DEPSDIR)/%:
	@git clone http://github.com/qleguennec/$(@F).git $@
	@make -s -C $@ purge

.PHONY: clean fclean re deps clean-deps re-deps test rendu purge get-%

clean:
	@rm $(LIBS) 2> /dev/null &&	\
	echo $(RED)--- static lib:'\t'$(CYAN)$(LIBS:$(LIBDIR)/%.a=%.a); true
	@rm $(OBJECTS) 2> /dev/null	\
	&& echo $(RED)--- obj:'\t'$(YELLOW)$(OBJECTS)$(END); true

fclean: clean
	@[ -f $(TARGET) ] && rm $(TARGET) \
	&& echo $(RED)--- target:'\t'$(END)$(BINDIR)/'\t'$(BLUE)$(NAME)$(END); true

re: fclean all

deps: $(addprefix $(DEPSDIR)/, $(LIBSRC))

clean-deps:
	@rm -rf $(DEPSDIR)

re-deps: clean-deps deps

test: rendu
	@test/test.sh $(ARGS)
	@test/test-functions-used.sh

rendu:
	@util/rendu.sh

purge:
	@util/purge.sh

get-%:
	@echo '$($*)'
