CC      = cc
CFLAGS  = -pthread -I/usr/include/gtk-3.0 \
	-I/usr/include/at-spi2-atk/2.0 \
	-I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 \
	-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
	-I/usr/include/atk-1.0 -I/usr/include/gtk-3.0 \
	-I/usr/include/gio-unix-2.0 -I/usr/include/cairo \
	-I/usr/include/pango-1.0 -I/usr/include/fribidi \
	-I/usr/include/harfbuzz -I/usr/include/gdk-pixbuf-2.0 \
	-I/usr/include/libmount -I/usr/include/blkid \
	-I/usr/include/cairo -I/usr/include/glib-2.0 \
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/pixman-1 -I/usr/include/uuid \
	-I/usr/include/freetype2 -I/usr/include/libpng16 \
	-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include

LDFLAGS = -lgtk-3 -latk-1.0 -lgio-2.0 -lgdk-3 -lpangocairo-1.0 \
	-lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject \
	-lgobject-2.0 -lglib-2.0 -lcairo -lglib-2.0

OBJS    = pieces.o mouse.o board.o main.o
OUT     = chess

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(OUT)

clean:
	rm -rf $(OUT) $(OBJS)

