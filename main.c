#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

extern void DrawBoard(); // board.c

int main(int argc, char** argv, char** envp)
{
  gtk_init(&argc, &argv);
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (window), "Chess");
  gtk_widget_set_size_request(window, 800, 800);

  GtkWidget* canvas = gtk_drawing_area_new();
  g_signal_connect(G_OBJECT (canvas), "expose-event",
                    G_CALLBACK (DrawBoard),
                    NULL
                  );
  
  gtk_container_add(GTK_CONTAINER (window), canvas);
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
			   G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
