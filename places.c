#include <math.h>

char* GetNote(int x, int y)
{
  char* ret;
  if (floor(x / 100) * 100 == 0) ret += 'A';
  else if (floor(x / 100) * 100 == 100) ret += 'B';
  else if (floor(x / 100) * 100 == 200) ret += 'C';
  else if (floor(x / 100) * 100 == 300) ret += 'D';
  else if (floor(x / 100) * 100 == 400) ret += 'E';
  else if (floor(x / 100) * 100 == 500) ret += 'F';
  else if (floor(x / 100) * 100 == 600) ret += 'G';
  else if (floor(x / 100) * 100 == 700) ret += 'H';

  if (floor(y / 100) * 100 == 0) ret += '1';
  else if (floor(y / 100) * 100 == 100) ret += '2';
  else if (floor(y / 100) * 100 == 200) ret += '3';
  else if (floor(y / 100) * 100 == 300) ret += '4';
  else if (floor(y / 100) * 100 == 400) ret += '5';
  else if (floor(y / 100) * 100 == 500) ret += '6';
  else if (floor(y / 100) * 100 == 600) ret += '7';
  else if (floor(y / 100) * 100 == 700) ret += '8';

  return ret;
}
