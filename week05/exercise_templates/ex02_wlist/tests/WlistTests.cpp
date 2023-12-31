#include "Wlist.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>


TEST(testWlistCaselessEmptyInput) {
  std::istringstream input{""};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("", output.str());
}


auto createWlistCaselessSuite() -> cute::suite {
  cute::suite wlistCaselessSuite{
    "Wlist Caseless Suite",
    {
      testWlistCaselessEmptyInput,
    }
  };
  return wlistCaselessSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto suiteResult = runner(createWlistCaselessSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}