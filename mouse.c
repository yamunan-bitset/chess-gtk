#include <stdio.h>
#include <gtk/gtk.h>
#include <math.h>

#include "estruct.h"

extern char GetX(double);        // notation.c
extern char GetY(double);        // notation.c
extern struct Piece* pieces[64]; // pieces.c

gboolean Clicked(GtkWidget* widget, GdkEventButton* event, gpointer user_data)
{
  if (event->type == GDK_BUTTON_PRESS)
    {
      GdkEventMotion* mouse = (GdkEventMotion*) event;
      int x = (guint) mouse->x, y = (guint) mouse->y;
      // Verbose
      printf("(%u,%u)\n", x,y);
      
      /*Coordinate*/
      double approxx = floor(x/100);
      double approxy = floor(y/100);
      printf("%c%c\n", GetX(approxx), GetY(approxy));
      
      /*Highlight Square*/
      cairo_t* cr = gdk_cairo_create(gtk_widget_get_window(GTK_WIDGET(widget)));
      cairo_set_fill_rule(cr, CAIRO_FILL_RULE_EVEN_ODD);
      cairo_fill(cr);
      cairo_save(cr);
      cairo_rectangle(cr, approxx*100, approxy*100, 100, 100);
      cairo_restore(cr);
      cairo_set_source_rgb(cr, 0, 1, 0);
      cairo_stroke(cr);  
      cairo_destroy(cr);
    }
  return TRUE;
}
