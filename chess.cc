#include "chess.hh"

Chess::Chess()
{ set_draw_func(sigc::mem_fun(*this, &Chess::on_draw)); }

Chess::~Chess()
{
}

void Chess::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  for (unsigned i = 0; i < 8; i++)
    for (unsigned j = 0; j < 8; j++)
      {
	cr->set_fill_rule(Cairo::Context::FillRule::EVEN_ODD);
	cr->fill();
	cr->save();
	cr->rectangle(i*100, j*100, 100, 100);
	cr->restore();
	if ((i + j) % 2 == 0) cr->set_source_rgb(1, 1, 1);
	else                  cr->set_source_rgb(0.36470588235294116f,
						 0.5764705882352941f,
						 0.7333333333333333f);
      }
  cr->set_fill_rule(Cairo::Context::FillRule::EVEN_ODD);
  cr->fill();
  cr->save();
  cr->rectangle(800, 800, 100, 100);
  cr->restore();
  cr->set_source_rgb(1, 1, 1);
  
  cr->stroke();
}
