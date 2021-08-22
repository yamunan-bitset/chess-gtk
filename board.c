#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

#include "estruct.h"

extern void LoadPieces(cairo_t*);  // pieces.c
extern struct Piece* pieces[64];   // pieces.c

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
	else                  cairo_set_source_rgb(cr, 0.36470588235294116f,
						   0.5764705882352941f,
						   0.7333333333333333f);
      }
      
      cairo_set_fill_rule(cr, CAIRO_FILL_RULE_EVEN_ODD);
      cairo_fill(cr);
      cairo_save(cr);
      cairo_rectangle(cr, 800, 800, 100, 100);
      cairo_restore(cr);
      cairo_set_source_rgb(cr, 1, 1, 1);
  
  cairo_stroke(cr);  

  /*Load Pieces*/
  LoadPieces(cr);
  
  /*Destroy*/
  /* This gives SIGSEGV
  for (unsigned i = 0; i < 64; i++)
    cairo_surface_destroy(pieces[i]->surface);
  */
  
  cairo_destroy(cr);
}
