#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

extern cairo_surface_t* surface[64];  // pieces.c
extern void LoadPieces(cairo_t*);     // pieces.c

void DrawBoard(GtkWidget* widget, GdkEventExpose* eev, gpointer data)
{
  cairo_t* cr = gdk_cairo_create(gtk_widget_get_window(GTK_WIDGET(widget)));

  /*Draw Board*/
  const char* squares[8][8];
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

  /*Load Pieces*/
  LoadPieces(cr);
  

  /*Destroy*/
  for (unsigned i = 0; i < 64; i++)
    cairo_surface_destroy(surface[i]);
  cairo_destroy(cr);
}
