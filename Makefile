# Directories
PROJECT		=	libftprintf
BINDIR		?=	.
SRCDIR		?=	src
BUILDDIR	?=	build
LIBDIR		?=	$(BUILDDIR)
DEPSDIR		?=	lib
INCLUDE		+=	includes
INCLUDE		+=	$(addsuffix /includes, $(addprefix $(DEPSDIR)/, $(LIBSRC)))
NAME		=	libftprintf.a

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
OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBS		=	$(addprefix $(LIBDIR)/, $(addsuffix .a, $(LIBSRC)))

all: $(NAME)
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR); true
	$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)+++ obj:'\t'$(END)$(BUILDDIR)/$(YELLOW) $(@F)$(END)

$(LIBDIR)/%.a: $(DEPSDIR)/%
	@[ -d $(BUILDDIR)/$* ] || mkdir -p $(BUILDDIR)/$*; true
	@										\
		DEPSDIR=$(CURDIR)/$(DEPSDIR)		\
		BINDIR=$(CURDIR)/$(BUILDDIR)		\
		BUILDDIR=$(CURDIR)/$(BUILDDIR)/$*	\
		LIBDIR=$(CURDIR)/$(LIBDIR)			\
		make -s -C $< > /dev/null
	@echo $(GREEN)+++ static lib:'\t'$(END)$(LIBDIR)/'\t'$(CYAN)$(@F)$(END)

$(NAME): $(LIBS) $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@$(foreach lib, $(LIBS), $(shell ar -x $(lib)))
	ar -r $(NAME) $(foreach lib, $(LIBS), $(shell ar -t $(lib) | grep ".o" | grep -v SYMDEF))
	@rm $(foreach lib, $(LIBS), $(shell ar -t $(lib) | grep ".o"))
	@rm "__.SYMDEF SORTED" || true
	@echo $(GREEN)+++ target:'\t'$(END)$(@D)/ $(BLUE)$(@F)$(END)

$(DEPSDIR)/%:
	@git clone http://github.com/qleguennec/$(@F).git $@
	@make -s -C $@ purge

.PHONY: clean fclean re deps clean-deps re-deps test rendu purge get-%%

clean:
	@rm $(LIBS) 2> /dev/null	\
	&& echo $(RED)--- static lib:'\t'$(CYAN)$(LIBS:$(LIBDIR)/%.a=%.a); true
	@rm $(OBJECTS) 2> /dev/null	\
	&& echo $(RED)--- obj:'\t'$(YELLOW)$(OBJECTS)$(END); true
	@rm -rf $(BUILDDIR)

fclean: clean
	@[ -f $(NAME) ] && rm $(NAME) \
	&& echo $(RED)--- target:'\t'$(END)$(BINDIR)/ $(BLUE)$(NAME)$(END); true

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
