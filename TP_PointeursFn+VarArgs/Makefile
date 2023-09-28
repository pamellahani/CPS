CC=gcc 
CFLAGS=-Wall -Werror

EXEC = essai_fap arg_var

all: ${EXEC}

essai_fap: essai_fap.o fap.o 
	$(CC) -o $@ $^

arg_var: arg_var.o
	$(CC) -o $@ $^

%.o:%.c fap.h
	$(CC) $(CFLAGS) -c $<

essai_fap.o: essai_fap.c fap.h

fap.o: fap.c fap.h

arg_var.o: arg_var.c arg_var.h

.PHONY: clean 

clean: 
	rm -f $(EXEC) *.o