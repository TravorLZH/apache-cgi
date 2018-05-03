SOURCES=$(wildcard *.c)
OBJ=$(SOURCES:.c=.o)
TARGETS=$(basename $(OBJ))
DEST=/usr/local/apache2/cgi-bin
define	GITIGNOREDS
# DO NOT EDIT
# This file is auto-generated by Makefile
# Ignore object and executable files
*.o
*.obj
*.a
*.exe
*.so
# Ignore specific targets
endef
export GITIGNOREDS
.PHONY:	all .gitignore clean
all:	.gitignore $(TARGETS)
$(TARGETS):	$(OBJ)
$(OBJ):	$(SOURCES)
install:
	(for target in $(TARGETS); do \
		install -m 777 $$target $(DEST); \
	done)
.gitignore:
	echo "$$GITIGNOREDS" > $@
	(for target in $(TARGETS); do \
		echo $$target >> $@; \
	done)
clean:
	rm -f *.o
	rm -f $(TARGETS)
