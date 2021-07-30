#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

gboolean MousePress(GtkWidget* widget, GdkEvent* event, gpointer user_data)
{
	GdkEventButton* e = (GdkEventButton*) event;
	if (e->button != 1) return FALSE;
	
	return FALSE;
}

gboolean MouseRelease(GtkWidget* widget, GdkEvent* event, gpointer user_data)
{
	GdkEventButton *e = (GdkEventButton*) event;

	if (e->button != 1) return FALSE;

	gtk_widget_queue_draw(widget);

	return FALSE;
}
