#include <stdio.h>
#include <gtk/gtk.h>
#include <math.h>

gboolean Clicked(GtkWidget* widget, GdkEventButton* event, gpointer user_data)
{
  if (event->type == GDK_BUTTON_PRESS)
    {
      GdkEventMotion* mouse = (GdkEventMotion*) event;
      int x = (guint) mouse->x, y = (guint) mouse->y;
      // Verbose
      printf("(%u,%u)\n", x,y);
      
      
      /*Coordinate*/
      char str[2];
      char strx, stry;
      /*x*/
      double approxx = floor(x/100);
      if (approxx == 0) str[0] = 'a';
      if (approxx == 1) str[0] = 'b';
      if (approxx == 2) str[0] = 'c';
      if (approxx == 3) str[0] = 'd';
      if (approxx == 4) str[0] = 'e';
      if (approxx == 5) str[0] = 'f';
      if (approxx == 6) str[0] = 'g';
      if (approxx == 7) str[0] = 'h';
      putchar(str[0]);
      /*y*/
      double approxy = floor(y/100);
      if (approxy == 0) str[1] = '8';
      if (approxy == 1) str[1] = '7';
      if (approxy == 2) str[1] = '6';
      if (approxy == 3) str[1] = '5';
      if (approxy == 4) str[1] = '4';
      if (approxy == 5) str[1] = '3';
      if (approxy == 6) str[1] = '2';
      if (approxy == 7) str[1] = '1';
      putchar(str[1]);
      putchar('\n');
      /*Highlight Clicked Squares*/
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
