#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>

//Partition algorithms (hint):
// * is_partitioned
// * partition
// * stable_partition
// * partition_copy
// * partition_point


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{2, 3, 5, 7, 1, 4, 6, 8, 9};
	auto expected = std::begin(in1) + 4;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_2) {
	auto in_out1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto expected = std::vector{2, 3, 5, 7, 1, 4, 6, 8, 9};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			is_prime);

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_3) {
	auto in1 = std::vector{2, 3, 5, 7, 1, 4, 6, 8, 9};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(res);
}


TEST(test_algorithm_4) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto out1 = std::vector<int>{};
	auto out2 = std::vector<int>{};
	auto expected1 = std::vector{2, 3, 5, 7};
	auto expected2 = std::vector{1, 4, 6, 8, 9};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			std::back_inserter(out2),
			is_prime);

	ASSERT_EQUAL(std::tie(expected1, expected2), std::tie(out1, out2));
}

TEST(test_algorithm_5) {
	auto in_out1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto expected = std::vector{7, 2,	3, 5, 4, 6, 1, 8, 9};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			is_prime);

	ASSERT_EQUAL(expected, in_out1);
}

}

auto createPartitionSuite() -> cute::suite {
	return cute::suite{
		"Partitioning Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
			test_algorithm_5,
		}
	};
}
