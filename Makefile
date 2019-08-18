CC=		cc

STDFLAGS=	-std=c11 -pedantic
DFLAGS=		-D_DEFAULT_SOURCE
OFLAGS=		-O2
WFLAGS=		-Wall \
		-Wextra \
		-Wconversion \
		-Wfloat-equal \
		-Wshadow \
		-Wpointer-arith \
		-Wcast-align \
		-Wstrict-prototypes \
		-Wstrict-overflow=5 \
		-Wwrite-strings \
		-Waggregate-return \
		-Wcast-qual \
		-Wundef \
		-Wunreachable-code \
		-Wuninitialized \
		-Wformat=2 \
		-Wno-format-nonliteral
FFLAGS=		-ftrapv
EXTRAFLAGS=	-Werror \
		-DNDEBUG
CFLAGS=		$(STDFLAGS) $(DFLAGS) $(OFLAGS) $(WFLAGS) $(FFLAGS) $(EXTRAFLAGS)
LDFLAGS=	-lreadline

SRC=		funk.c \
		get_builtin_meta.c \
		obj_dump.c \
		vm_init.c \
		vm_dump.c

BIN=		funk

.PHONY: all debug

$(BIN): $(SRC)
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(LDFLAGS)

all: $(BIN)

debug: OFLAGS=-Og
debug: EXTRAFLAGS=-g -fno-omit-frame-pointer
debug: all

clean:
	rm -f $(BIN)
