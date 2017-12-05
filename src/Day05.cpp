#include "Solution.hpp"
#include <vector>
#include <iterator>

template <>
void
solve<Day05>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<int> inst {std::istream_iterator<int>{is}, {}};
  int index{0}, steps{0}, n(inst.size());
  while (index >= 0 && index < n) {
    ++steps;
    if (part2 && inst[index] >= 3) {
      index += inst[index]--;
    } else {
      index += inst[index]++;
    }
  }
  os << steps << '\n';
}
