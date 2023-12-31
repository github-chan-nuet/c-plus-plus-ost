#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <numeric>
#include <iterator>
#include <string>

//Numeric algorithms (hint):
// * accumulate
// * inner_product
// * partial_sum
// * adjacent_difference
// * iota


namespace {

TEST(test_algorithm_1) {
	auto out1 = std::vector<int>(8);
	auto expected = std::vector{0, 1, 2, 3, 4, 5, 6, 7};

	std::xxxxx(
			std::begin(out1),
			std::end(out1),
			0);

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_2) {
	auto in1 = std::vector{1, 2, 4, 3, 9, 5, 7};
	auto out1 = std::vector<int>(in1.size());
	auto expected = std::vector{1, 1, 2, -1, 6, -4, 2};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_3) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6};
	auto expected = 121;

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			100);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_4) {
	auto in1 = std::vector{1, 20, 300, 4000, 50000};
	auto out1 = std::vector<int>(in1.size());
	auto expected = std::vector{1, 21,321,4321, 54321};

	std::xxxxxx(std::begin(in1), std::end(in1), std::begin(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_5) {
	auto in1 = std::vector{1, 2, 3, 2, 1};
	auto in2 = std::vector{'a', 'b', 'c', 'd', 'e'};
	auto expected = std::string{"begin, 1a, 2b, 3c, 2d, 1e"};

	auto res = std::xxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::string{"begin"},
			[](std::string l, std::string r) {return l + ", " + r;},
			[](int i, char c) {return std::to_string(i) + c;});

	ASSERT_EQUAL(expected, res);
}

}

auto createNumericSuite() -> cute::suite {
	return cute::suite{
		"Numeric Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
			test_algorithm_5,
		}
	};
}
