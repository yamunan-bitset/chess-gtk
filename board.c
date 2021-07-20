#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

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
  cairo_destroy(cr);
}
