#ifndef __ESTRUCT__CHESS_GTK__H__
#define __ESTRUCT__CHESS_GTK__H__

enum Pieces
  {
    space = 0,
    w_king = 4 , w_pawn   = 6,  w_bishop = 3,
    w_rook = 1 , w_knight = 2,  w_queen  = 5,
    b_king = -4, b_pawn   = -6, b_bishop = -3,
    b_rook = -1, b_knight = -2, b_queen  = -5,
  };

struct Piece
{
  cairo_surface_t* surface; // cairo surface
  int x, y;                 // location
};

#endif
