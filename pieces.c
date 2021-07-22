#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

int board[8][8] =
  {
#include "board.inc"
  };

enum Pieces
  {
    space = 0,
    w_king = 4 , w_pawn   = 6,  w_bishop = 3,
    w_rook = 1 , w_knight = 2,  w_queen  = 5,
    b_king = -4, b_pawn   = -6, b_bishop = -3,
    b_rook = -1, b_knight = -2, b_queen  = -5,
  };

cairo_surface_t* surface[64];

static inline cairo_surface_t* DrawPiece(cairo_t* cr, const char* file, unsigned xpos, unsigned ypos)
{
  cairo_surface_t* surface = cairo_image_surface_create_from_png(file);
  cairo_set_source_surface(cr, surface, ypos*100, xpos*100);
  cairo_paint(cr);
  return surface;
}

void LoadPieces(cairo_t* cr)
{
  GdkDragContext* drag_context;
  for (unsigned i = 0; i < 8; i++)
    for (unsigned j = 0; j < 8; j++)
      {
	switch (board[i][j])
	  {
	  case w_king:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_king.png", i, j);   break;
	  case w_queen:  surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_queen.png", i, j);  break;
	  case w_knight: surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_knight.png", i, j); break;
	  case w_pawn:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_pawn.png", i, j);   break;
	  case w_bishop: surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_bishop.png", i, j); break;
	  case w_rook:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/w_rook.png", i, j);   break;
	  case b_king:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_king.png", i, j);   break;
	  case b_queen:  surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_queen.png", i, j);  break;
	  case b_knight: surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_knight.png", i, j); break;
	  case b_pawn:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_pawn.png", i, j);   break;
	  case b_bishop: surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_bishop.png", i, j); break;
	  case b_rook:   surface[j * 8 + i] = DrawPiece(cr, "data/assets/b_rook.png", i, j);   break;
	  case space:                                                                          break;
	  }
	gtk_drag_set_icon_surface(drag_context, surface[j * 8 + i]);
      }
}
