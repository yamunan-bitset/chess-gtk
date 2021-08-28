#include "chess.hh"

#include <gtkmm/application.h>
#include <gtkmm/window.h>

class ChessWindow : public Gtk::Window
{
public:
  ChessWindow()
  {
    set_title("Chess");
    set_child(chess);
    set_default_size(800, 800);
  }
  
protected:
  Chess chess;
};

int main(int argc, char** argv)
{
  auto app = Gtk::Application::create("org.gtkmm.chess");

  return app->make_window_and_run<ChessWindow>(argc, argv);
}
