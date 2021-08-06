#include <stdio.h>
#include <gtk/gtk.h>
#include <math.h>

gboolean Clicked(GtkWidget* widget, GdkEventButton* event, gpointer user_data)
{
  if (event->type == GDK_BUTTON_PRESS)
    {
      GdkEventMotion* mouse = (GdkEventMotion*) event;
      int x = (guint) mouse->x, y = (guint) mouse->y;
      printf("(%u,%u)\n", x,y);
    }
  return TRUE;
}
