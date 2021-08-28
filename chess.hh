#ifndef __CHESS__HH__
#define __CHESS__HH__

#include <gtkmm/drawingarea.h>

class Chess : public Gtk::DrawingArea
{
public:
  Chess();
  virtual ~Chess();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

  double size, x, y;
};

#endif
