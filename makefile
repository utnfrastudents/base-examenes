PROJECT = base-practica-c
OBJDIR = obj/Debug/
DEBUGDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
RMFLAGS = -rf
WFLAGS = -Wall
LOG = 1>> build.log
SRC = main.c
OBJ = main.o
PERC = persons.c
PERH = persons.h
PERO = persons.o
ENTC = entities.c
ENTH = entities.h
ENTO = entities.o
MENC = menu.c
MENH = menu.h
MENO = menu.o
INPC = inputs.c
INPH = inputs.h
INPO = inputs.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o
STRC = structs.c
STRH = structs.h
STRO = structs.o

rebuild: clean build
build: $(PROJECT)
	@date $(LOG) \
	&& echo "Se ejecuta el programa.\n" $(LOG) \
	&& ./$(DEBUGDIR)$^
$(PROJECT): $(OBJDIR)$(STRO) $(OBJDIR)$(ARRO) $(OBJDIR)$(INPO) $(OBJDIR)$(MENO) $(OBJDIR)$(ENTO) $(OBJDIR)$(PERO) $(OBJDIR)$(OBJ)
	@$(CC) $(WFLAGS) $^ -o $(DEBUGDIR)$@
$(OBJDIR)$(OBJ): $(PERH) $(SRC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC) \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto main.c" $(LOG)
$(OBJDIR)$(PERO): $(PERC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto persons.c" $(LOG)
$(OBJDIR)$(ENTO): $(ENTC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto entity.c" $(LOG)
$(OBJDIR)$(MENO): $(MENC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto menu.c" $(LOG)
$(OBJDIR)$(INPO): $(INPC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto inputs.c" $(LOG)
$(OBJDIR)$(ARRO): $(ARRC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto arrays.c" $(LOG)
$(OBJDIR)$(STRO): $(STRC)
	@date $(LOG) \
	&& echo "Se crean los directorios de compilacion." $(LOG) \
	&& mkdir -p $(OBJDIR) \
	&& mkdir -p $(DEBUGDIR) \
	&& cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^ \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto structs.c" $(LOG)
clean:
	@$(RM) $(PROJECT).layout $(PROJECT).depend build.log \
	&& $(RM) $(RMFLAGS) bin/ obj/ \
	&& date $(LOG) \
	&& echo "Se eliminan archivos y directorios de compilacion." $(LOG)
