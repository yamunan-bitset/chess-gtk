CC      = cc
CFLAGS  = $(shell pkg-config --cflags gtk+-3.0) -g
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)
OBJS    = pieces.o board.o main.o
OUT     = chess

all: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(OUT)

clean:
	rm -rf $(OUT) $(OBJS)

