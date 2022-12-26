C_SOURCES = $(wildcard matrix/*.c neural/*.c util/*.c *.c)
HEADERS = $(wildcard matrix/*.h neural/*.h util/*.h *.h)
OBJ = ${C_SOURCES:.c=.o}
CFLAGS = -fopenmp -DNUM_THREADS=8

MAIN = main
CC = /usr/bin/gcc
LINKER = /usr/bin/ld

main: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@ -lm

# Generic rules
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@ -lm

.PHONY: clean
clean:
	rm matrix/*.o *.o neural/*.o util/*.o ${MAIN}

.PHONY: run
run: ${MAIN}
	./${MAIN}

