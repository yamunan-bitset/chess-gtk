#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

extern enum Pieces;               // pieces.c
extern int squares[64];           // pieces.c
extern void LoadPieces();         // pieces.c


void DrawBoard(GtkWidget* widget, GdkEventExpose* eev, gpointer data)
{
  cairo_t* cr = gdk_cairo_create(widget->window);
  
  for (unsigned i = 0; i < 8; i++)
    for (unsigned j = 0; j < 8; j++)
      {
	cairo_set_fill_rule(cr, CAIRO_FILL_RULE_EVEN_ODD);
	cairo_fill(cr);
	cairo_save(cr);
	cairo_rectangle(cr, i*100, j*100, 100, 100);
	cairo_restore(cr);
	if ((i + j) % 2 == 0) cairo_set_source_rgb(cr, 1, 1, 1);
	else                  cairo_set_source_rgb(cr, 0.36470588235294116f, 0.5764705882352941f, 0.7333333333333333f);
      }
  
  cairo_stroke(cr);  
  
  LoadPieces(cr);
  
  cairo_paint(cr);
  
  cairo_destroy(cr);
}
