#include "data.h"

void
data::print (void)
{
  std::cout << "N: " << number << std::endl;
  std::cout << "LL: " << lower_limit << std::endl;
  std::cout << "UL: " << upper_limit << std::endl;
  std::cout << "V: " << valid << std::endl;
}
