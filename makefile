CC=gcc
SYMBOLS=-D_GNU_SOURCE
CFLAGS=-c -Wall -fms-extensions -pedantic -std=c11 `pkg-config --cflags sdl2 glib-2.0`
LDFLAGS=`pkg-config --libs sdl2 glib-2.0 ` -lSDL2_image -lSDL2_mixer \
	-lSDL2_net -lSDL2_ttf

SRC_DIR=./ ./components/ ./entities/ ./subsystems/ ./managers/
INCLUDES=$(foreach dir, $(SRC_DIR), -I$(dir))
SOURCES=$(foreach dir, $(SRC_DIR), $(wildcard $(dir)*.c))
HEADERS:=$(filter-out ./main.h,$(SOURCES:.c=.h))
# RAW_HEADERS=$(SOURCES:.c=.h)


VIM_GARBAGE:=$(foreach dir, $(SRC_DIR), $(dir).*.swp)
GEDIT_GARBAGE:=$(foreach dir, $(SRC_DIR), $(dir)*~)
OBJECTS=$(SOURCES:.c=.o)
EXE=Game

EXE: $(HEADERS) $(SOURCES) $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(SYMBOLS) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm $(VIM_GARBAGE) $(GEDIT_GARBAGE) $(OBJECTS) $(EXE) -rf

again:
	@make clean && make

info:
	@echo SOURCES: $(SOURCES)
	@echo HEADERS: $(HEADERS)
	@echo VIM_GARBAGE: $(VIM_GARBAGE)
	@echo GEDIT_GARBAGE: $(GEDIT_GARBAGE)
	
