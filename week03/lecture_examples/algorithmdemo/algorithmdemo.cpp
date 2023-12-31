#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <ranges>
#include <string>
#include <vector>

auto count_blanks(std::string const & s) -> std::size_t {
  return count(begin(s), end(s), ' ');
}

auto count_blanks_ranges(std::string_view s) -> std::size_t {
  return std::ranges::count(s, ' ');
}

auto copydemo(std::vector<int> v, std::ostream &os) -> void {
  using out = std::ostream_iterator<int>;
  copy(begin(v), end(v), out{os, ", "});
  v.push_back(42);
  copy(begin(v), begin(v) + 2, std::back_inserter(v));
  os << '\n';
  copy(begin(v), end(v), out{os, ", "});
}

auto copydemo_ranges(std::vector<int> v, std::ostream &os) -> void {
  using out = std::ostream_iterator<int>;
  std::ranges::copy(v, out{os, ", "});
  v.push_back(42);
  std::ranges::copy(std::ranges::take_view{v, 2}, std::back_inserter(v));
  os << '\n';
  std::ranges::copy(v, out{os, ", "});
}

auto print(int x) -> void { std::cout << "print: " << x << '\n'; }

auto for_each_demo(std::ostream &os) -> void {
  std::vector<int> v{5, 4, 3, 2, 1};
  os << std::accumulate(begin(v), end(v), 0) << " = sum\n";

  std::for_each(begin(v), end(v), [&os](auto x) { os << x << '\n'; });
  std::for_each(crbegin(v), crend(v), print);

  copydemo(v, os);
}

auto for_each_demo_ranges(std::ostream &os) -> void {
  std::vector<int> v{5, 4, 3, 2, 1};
  os << std::accumulate(begin(v), end(v), 0) << " = sum\n";

  std::ranges::for_each(v, [&os](auto x) { os << x << '\n'; });
  std::ranges::for_each(std::views::reverse(v), print);

  copydemo_ranges(v, os);
}

auto random_int() -> int {
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(0, 100);
  return dis(gen);
}

auto contains_with_loop(std::vector<int> const &values, int const v) -> bool {
  auto const end = std::end(values);
  for (auto it = std::begin(values); it != end; ++it) {
    if (*it == v) {
      return true;
    }
  }
  return false;
}

 //std::ranges::contains might be standardized
auto contains_with_ranges(std::vector<int> const & values, int const v) -> bool {
  return std::ranges::find(values, v) != std::cend(values);
}

auto generate_find_demo(std::ostream &os) -> void {
  std::vector<int> v{};
  generate_n(back_inserter(v), 100, random_int);
  auto zero_it = find(begin(v), end(v), 0);
  if (zero_it == end(v)) {
    os << "\nno zero found \n";
  } else {
    os << "\nfound zero at position:" << distance(begin(v), zero_it) << '\n';
  }
  auto odd = find_if(begin(v), end(v), [](auto x) { return x % 2; });
  if (odd == end(v)) {
    os << "no odd number found\n";
  } else {
    os << "found odd number:" << *odd
       << "\nat position:" << distance(begin(v), odd) << '\n';
  }
  os << std::boolalpha;
  os << "contains 42: " << contains_with_loop(v, 42) << '\n';
  os << "contains 42: "
     << std::any_of(cbegin(v), cend(v), [](int i) { return i == 42; }) << '\n';
}

auto generate_find_demo_ranges(std::ostream &os) -> void {
  std::vector<int> v{};
  std::generate_n(std::back_inserter(v), 100, random_int);
  auto zero_it = std::ranges::find(v, 0);
  if (zero_it == std::end(v)) {
    os << "\nno zero found \n";
  } else {
    os << "\nfound zero at position:" << distance(begin(v), zero_it) << '\n';
  }
  auto odd = std::ranges::find_if(v, [](auto x) { return x % 2; });
  if (odd == std::end(v)) {
    os << "no odd number found\n";
  } else {
    os << "found odd number:" << *odd
       << "\nat position:" << std::distance(begin(v), odd) << '\n';
  }
  os << std::boolalpha;
  os << "contains 42: " << contains_with_ranges(v, 42) << '\n';
  os << "contains 42: "
     << std::ranges::any_of(v, [](int i) { return i == 42; }) << '\n';
}

auto generate_demo(std::ostream &os) -> void {
  std::vector<double> powerOfTwos{};
  std::generate_n(std::back_inserter(powerOfTwos), 10,
                  [x = 1.0]() mutable { return x *= 2.0; });
  using out = std::ostream_iterator<double>;
  std::copy(begin(powerOfTwos), end(powerOfTwos), out{os, " "});
  os << '\n';
}

auto generate_demo_ranges(std::ostream &os) -> void {
  std::vector<double> powerOfTwos{};
  std::generate_n(std::back_inserter(powerOfTwos), 10,
                  [x = 1.0]() mutable { return x *= 2.0; });
  using out = std::ostream_iterator<double>;
  std::ranges::copy(powerOfTwos, out{os, " "});
  os << '\n';
}

auto count_demo(std::ostream &os) -> void {
  std::vector<int> v{};
  generate_n(back_inserter(v), 10, random_int);
  os << std::count(v.begin(), v.end(), 42) << " times 42\n";
  os << std::count_if(begin(v), end(v), [](int x) { return x % 2 == 0; })
     << " even numbers\n";
  os << "is there a zero: " << std::boolalpha
     << any_of(begin(v), end(v), [](int x) { return x == 0; }) << '\n';
}

auto count_demo_ranges(std::ostream &os) -> void {
  std::vector<int> v{};
  std::generate_n(back_inserter(v), 10, random_int);
  os << std::ranges::count(v, 42) << " times 42\n";
  os << std::ranges::count_if(v, [](int x) { return x % 2 == 0; })
     << " even numbers\n";
  os << "is there a zero: " << std::boolalpha
     << std::ranges::any_of(v, [](int x) { return x == 0; }) << '\n';
}

auto demo_algorithms() -> void {
  std::string s{"A journey of a thousand miles begins with a single step"};
  std::cout << count(begin(s), end(s), ' ') << " blanks\n";
  std::cout << "distance: " << distance(begin(s), end(s)) << '\n';
  std::cout << "in a string of length: " << s.size() << '\n';
  std::cout << count_blanks(s) << " blanks\n";

  for_each_demo(std::cout);
  generate_find_demo(std::cout);
  generate_demo(std::cout);
  count_demo(std::cout);
}

auto demo_ranges() -> void {
  std::string s{"A journey of a thousand miles begins with a single step"};
  std::cout << std::ranges::count(s, ' ') << " blanks\n";
  std::cout << "distance: " << distance(begin(s), end(s)) << '\n';
  std::cout << "in a string of length: " << s.size() << '\n';
  std::cout << count_blanks_ranges(s) << " blanks\n";

  for_each_demo_ranges(std::cout);
  generate_find_demo_ranges(std::cout);
  generate_demo_ranges(std::cout);
  count_demo_ranges(std::cout);
}

auto main() -> int {
  demo_algorithms();
  demo_ranges();
}
