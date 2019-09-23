PROJECT = base-practica-c
OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
INPC = inputs.c
INPH = inputs.h
INPO = inputs.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o
STRC = structs.c
STRH = structs.h
STRO = structs.o

debug: $(PROJECT)
	./$(EXEDIR)$^
$(PROJECT): $(OBJDIR)$(ARRO) $(OBJDIR)$(STRO) $(OBJDIR)$(INPO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(EXEDIR)$@
$(OBJDIR)$(OBJ): $(INPH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(INPO): $(INPC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ARRO): $(ARRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(STRO): $(STRC)
	mkdir -p $(OBJDIR) \
	&& mkdir -p $(EXEDIR) \
	&& cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) $(PROJECT).layout $(PROJECT).depend $(OBJDIR)*.o $(EXEDIR)$(PROJECT)
