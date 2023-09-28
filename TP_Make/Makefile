CC = gcc 
CFLAGS = -Wall -W -Werror

EXEC = essai_pile	

all: ${EXEC}

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

pile.o : pile.c pile.h 
		$(CC) $(CFLAGS) -c pile.c

pile_io.o : pile_io.c pile_io.h pile.h
			$(CC) $(CFLAGS) -c pile_io.c

essai_pile.o: essai_pile.c pile.h pile_io.h
			$(CC) $(CFLAGS) -c essai_pile.c

essai_pile: essai_pile.o pile.o pile_io.o
			$(CC) -o essai_pile essai_pile.o pile.o pile_io.o

.PHONY:clean 

clean: 
	rm -f $(EXEC) *.o