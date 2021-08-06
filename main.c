#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

extern void DrawBoard(GtkWidget*, GdkEventExpose*, gpointer);          // board.c
extern gboolean Clicked(GtkWidget*, GdkEventButton*, gpointer); // clicked.c

int main(int argc, char** argv, char** envp)
{
  /*Init*/
  gtk_init(&argc, &argv);
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (window), "Chess");
  gtk_widget_set_size_request(window, 800, 800);

  /*Rendering*/
  GtkWidget* canvas = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (window), canvas);
  g_signal_connect(G_OBJECT (canvas), "draw",
                    G_CALLBACK (DrawBoard),
                    NULL
		   );

  /*Mouse*/
  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
  g_signal_connect(window, "button-press-event",
		   G_CALLBACK(Clicked),
		   NULL
		   );

  /*Cleanup*/
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
			   G_CALLBACK(gtk_main_quit),
			   NULL
			   );

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
