CC := gcc
AR := ar

CFLAGS := $(shell sdl2-config --cflags) -Wall -I../include
ARFLAGS := rcs

SRC := draw.c tools.c window.c
OBJ := $(SRC:.c=.o)

LIBOUT := ../lib/libgen.a

all: $(LIBOUT)

$(LIBOUT): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBOUT)
