PROJECT = base-practica-c
OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
INPC = input.c
INPH = input.h
INPO = input.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o

$(PROJECT): $(OBJDIR)$(INPO) $(OBJDIR)$(ARRO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(EXEDIR)$@
$(OBJDIR)$(OBJ): $(ARRH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(ARRO): $(ARRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(INPO): $(INPC)
	mkdir -p $(OBJDIR) \
	&& mkdir -p $(EXEDIR) \
	&& cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) $(PROJECT).layout $(PROJECT).depend $(OBJDIR)*.o $(EXEDIR)$(PROJECT)
debug: $(PROJECT)
	./$(EXEDIR)$^