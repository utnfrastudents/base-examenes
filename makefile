PROJECT = base-practica-c
OBJDIR = obj/Debug/
DEBUGDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
RMFLAGS = -rf
WFLAGS = -Wall
LOG = >> build.log
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

rebuild: clean build
build: $(PROJECT)
	@date $(LOG) \
	&& echo "Se ejecuta el programa." $(LOG) \
	&& ./$(DEBUGDIR)$^
$(PROJECT): $(OBJDIR)$(STRO) $(OBJDIR)$(ARRO) $(OBJDIR)$(INPO) $(OBJDIR)$(OBJ)
	@$(CC) $(WFLAGS) $^ -o $(DEBUGDIR)$@
$(OBJDIR)$(OBJ): $(INPH) $(SRC)
	@cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC) \
	&& cd $(UPDIR) && echo "Se compila a codigo objeto main.c" $(LOG)
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
