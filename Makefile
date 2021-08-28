CXX        = c++
CXXFLAGS   = -I/usr/include/gtkmm-4.0 -I/usr/lib/gtkmm-4.0/include \
		-I/usr/include/giomm-2.68 -I/usr/lib/giomm-2.68/include \
		-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include \
		-I/usr/include/libmount -I/usr/include/blkid \
		-I/usr/include/glibmm-2.68 -I/usr/lib/glibmm-2.68/include \
		-I/usr/include/sigc++-3.0 -I/usr/lib/sigc++-3.0/include \
		-I/usr/include/gtk-4.0 -I/usr/include/pango-1.0 \
		-I/usr/include/harfbuzz -I/usr/include/freetype2 \
		-I/usr/include/libpng16 -I/usr/include/fribidi \
		-I/usr/include/cairo -I/usr/include/lzo \
		-I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 \
		-I/usr/include/graphene-1.0 -I/usr/lib/graphene-1.0/include \
		-I/usr/include/gio-unix-2.0 -I/usr/include/cairomm-1.16 \
		-I/usr/lib/cairomm-1.16/include -I/usr/include/pangomm-2.48 \
		-I/usr/lib/pangomm-2.48/include -I/usr/include/gtk-4.0/unix-print \
		-mfpmath=sse -msse -msse2 -pthread
LINKERLIBS = -lgtkmm-4.0 -lpangomm-2.48 -lgiomm-2.68 -lglibmm-2.68 \
		-lcairomm-1.16 -lsigc-3.0 -lgtk-4 -lpangocairo-1.0 \
		-lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0            \
		-lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0   \
		-lgobject-2.0 -lglib-2.0
OUT        = chess
OBJS       = chess.o main.o 
build: $(OBJS)
	$(CXX) -o $(OUT) $(LINKERLIBS) $(CXXFLAGS)

clean:
	rm -rf $(OUT) $(OBJS)
