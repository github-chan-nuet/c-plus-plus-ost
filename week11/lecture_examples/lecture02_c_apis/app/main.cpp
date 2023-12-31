#include "demangle.hpp"
#include "plain_demangle.hpp"

#include <iostream>

auto main() -> int
{
	auto mangled_name = "_Z12frobnibulateRK4FrobR12Combobulator";

	auto classic_demangled = demangle(mangled_name);
	auto plain_demangled = plain_demangle(mangled_name);

	std::cout << "demangle(\"" << mangled_name << "\") == " << classic_demangled << '\n'
			  << "plain_demangle(\"" <<  mangled_name << "\") == " << plain_demangled << '\n';
}
