EXEC = bomberman
SOURCES= main.c perso.c game.c
OBJECTS =$(SOURCES: .c=.o)
CC=gcc
CFLAGS = -std=gnu99 -Wall -Werror
.PHONY: default clean

default:$(EXEC)

main.o: main.c game.h
perso.o: perso.c perso.h
game.o: game.c game.h perso.h

%.o: %.c
		$(CC) -o $@ -c $<$(CFLAGS)

$(EXEC):$(OBJECTS)
		$(CC) -o $@ $^

clean:
		rm $(EXEC) $(OBJECTS) $(SOURCES:.c=.c~) $(SOURCES:.c=.h~)
