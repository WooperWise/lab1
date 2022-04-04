CC=gcc
CFILES=main.c matrix.c print.c errors.c
LDFLAGS=-lm -std=c11 -g
OFILE=main

all:
	${CC} ${CFILES} -o ${OFILE} ${LDFLAGS}
