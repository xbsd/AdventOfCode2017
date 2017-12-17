#include "Solution.hpp"
#include <iterator>
#include <vector>

template <>
void
solve<Day17>(bool part2, std::istream& is, std::ostream& os)
{
  int incr;
  is >> incr;
  if (part2) {
    int afterZero{0}, i{0};
    for (int n{1}; n <= 50'000'000; ++n)
      if ((i = (i + incr) % n + 1) == 1)
        afterZero = n;
    os << afterZero << '\n';
  } else {
    std::vector<int> buf{0};
    buf.reserve(2017);
    int p{0};
    for (int n{1}; n <= 2017; ++n) {
      p = ((p + incr) % std::size(buf)) + 1;
      buf.insert(std::begin(buf) + p, n);
    }
    os << buf[(p + 1) % buf.size()] << '\n';
  }
}
