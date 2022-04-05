CC=gcc
CFILES=main.c matrix.c print.c errors.c
CFILESTEST=test.c matrix.c print.c errors.c
LDFLAGS=-lm -std=c11 -g
OFILE=main
OFILETEST=test

all:
	${CC} ${CFILES} -o ${OFILE} ${LDFLAGS}

test:
	${CC} ${CFILESTEST} -o ${OFILETEST} ${LDFLAGS}
