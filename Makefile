# Auteurs: Jordan Demartin & Rémy Gaudru
# Variables

H = ./Header/

SRC = ./Src/

CC = gcc

CFLAGS = -lgraph

EXE = Taquin

OFILES = menu.o \
	 set_up.o \
	 moving.o \
     main.o

# But par default
 
but : ${EXE}
 
# Regles essentiels
 
menu.o : $(SRC)menu.c $(H)menu.h $(H)set_up.h
	$(CC) $(CFLAGS) -c $(SRC)menu.c

set_up.o : $(SRC)set_up.c $(H)menu.h $(H)set_up.h $(H)moving.h
	$(CC) $(CFLAGS) -c $(SRC)set_up.c 

moving.o : $(SRC)moving.c $(H)menu.h $(H)moving.h
	$(CC) $(CFLAGS) -c $(SRC)moving.c 

main.o : $(SRC)main.c $(H)menu.h $(H)set_up.h $(H)moving.h
	$(CC) $(CFLAGS) -c $(SRC)main.c

${EXE} : ${OFILES}
	$(CC) -o ${EXE} ${OFILES} $(CFLAGS)
 
# Regles optionnelles
 
clean :
	-rm -f ${OFILES} ${EXE}
