#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>
#include <cairo/cairo-svg.h>

enum Board
{
  space = 0, king = 1, pawn = 2, knight = 3, bishop = 4, rook = 5, queen = 6,
  white = 8, black = 16
};

void DrawBoard(GtkWidget* widget, GdkEventExpose* eev, gpointer data)
{
  cairo_t* cr = gdk_cairo_create (widget->window);
  
  for (unsigned i = 0; i < 8; i++)
    for (unsigned j = 0; j < 8; j++)
      {
	cairo_set_fill_rule(cr, CAIRO_FILL_RULE_EVEN_ODD);
	cairo_fill(cr);
	cairo_save(cr);
	cairo_rectangle(cr, i*100, j*100, 100, 100);
	cairo_restore(cr);
	if ((i + j) % 2 == 0) cairo_set_source_rgb(cr, 1, 1, 1);
	else                  cairo_set_source_rgb(cr, 0, 0, 0);
      }

  cairo_stroke(cr);  
  
  int squares[64];
  squares[0] = white | queen;
  // TODO: SVG: https://zetcode.com/gfx/cairo/cairobackends/
  cairo_surface_t* image = cairo_svg_surface_create("data/assets/b_queen.png", 100, 100);
  cairo_set_source_surface(cr, image, 10, 10);
  cairo_paint(cr);
  
  cairo_destroy(cr);
}
