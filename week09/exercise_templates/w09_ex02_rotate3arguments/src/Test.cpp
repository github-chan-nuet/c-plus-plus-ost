#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "rotate3arguments.h"

#include <tuple>

void test_rotate_1_2_3() {
	int a = 1, b = 2, c = 3;
	auto expected = std::make_tuple(2, 3, 1);

	rotate3arguments(a, b, c);

	ASSERT_EQUAL(expected, std::tie(a, b, c));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(test_rotate_1_2_3));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
