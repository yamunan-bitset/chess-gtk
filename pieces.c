#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

#include "estruct.h"

extern char GetX(double); // notation.c
extern char GetY(double); // notation.c

int board[8][8] =
  {
#include "board.inc"
  };

struct Piece* pieces[64];

struct Piece* DrawPiece(cairo_t* cr, const char* file, unsigned xpos, unsigned ypos)
{
  struct Piece* piece;
  cairo_surface_t* surface = cairo_image_surface_create_from_png(file);
  cairo_set_source_surface(cr, surface, ypos*100, xpos*100);
  cairo_paint(cr);
  piece->surface = surface;
  piece->x = xpos*100;
  piece->y = ypos*100;
  printf("%d, %d\n", piece->x, piece->y);
  printf("%c%c\n", GetX(piece->x), GetY(piece->y));
  return piece;
}

void LoadPieces(cairo_t* cr)
{
  for (unsigned i = 0; i < 8; i++)
    for (unsigned j = 0; j < 8; j++)
      {
	switch (board[i][j])
	  {
	  case w_king:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_king.png", i, j);   break;
	  case w_queen:  pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_queen.png", i, j);  break;
	  case w_knight: pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_knight.png", i, j); break;
	  case w_pawn:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_pawn.png", i, j);   break;
	  case w_bishop: pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_bishop.png", i, j); break;
	  case w_rook:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/w_rook.png", i, j);   break;
	  case b_king:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_king.png", i, j);   break;
	  case b_queen:  pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_queen.png", i, j);  break;
	  case b_knight: pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_knight.png", i, j); break;
	  case b_pawn:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_pawn.png", i, j);   break;
	  case b_bishop: pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_bishop.png", i, j); break;
	  case b_rook:   pieces[j * 8 + i] = DrawPiece(cr, "data/assets/b_rook.png", i, j);   break;
	  case space:                                                                         break;
	  }
      }
}
