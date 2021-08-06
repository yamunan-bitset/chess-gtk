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
      if (floor(x/100) == 0) str[0] = 'a';
      if (floor(x/100) == 1) str[0] = 'b';
      if (floor(x/100) == 2) str[0] = 'c';
      if (floor(x/100) == 3) str[0] = 'd';
      if (floor(x/100) == 4) str[0] = 'e';
      if (floor(x/100) == 5) str[0] = 'f';
      if (floor(x/100) == 6) str[0] = 'g';
      if (floor(x/100) == 7) str[0] = 'h';
      putchar(str[0]);
      /*y*/
      if (floor(y/100) == 0) str[1] = '8';
      if (floor(y/100) == 1) str[1] = '7';
      if (floor(y/100) == 2) str[1] = '6';
      if (floor(y/100) == 3) str[1] = '5';
      if (floor(y/100) == 4) str[1] = '4';
      if (floor(y/100) == 5) str[1] = '3';
      if (floor(y/100) == 6) str[1] = '2';
      if (floor(y/100) == 7) str[1] = '1';
      putchar(str[1]);
      putchar('\n');
    }
  return TRUE;
}
