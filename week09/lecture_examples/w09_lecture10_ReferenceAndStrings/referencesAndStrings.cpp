#include <iostream>
#include <string>

template <typename T>
auto _min(T const & left, T const & right) -> T const & {
  return left < right ? left : right;
}

auto main() -> int {
	using namespace std::string_literals;
	std::cout << _min("C++"s, "Java"s);
}
