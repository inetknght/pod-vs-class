#include <iostream>

#if ! POD_VS_CLASS_DISABLED
#include "pod-vs-class.cpp"
#else // POD_VS_CLASS_DISABLED
#include <cstdint>
namespace pod_vs_class {

	using ::std::int8_t;
	using ::std::int16_t;
	using ::std::int32_t;
	using ::std::int64_t;

	using ::std::uint8_t;
	using ::std::uint16_t;
	using ::std::uint32_t;
	using ::std::uint64_t;

	using ::std::int_least8_t;
	using ::std::int_least16_t;
	using ::std::int_least32_t;
	using ::std::int_least64_t;

	using ::std::uint_least8_t;
	using ::std::uint_least16_t;
	using ::std::uint_least32_t;
	using ::std::uint_least64_t;

	using ::std::int_fast8_t;
	using ::std::int_fast16_t;
	using ::std::int_fast32_t;
	using ::std::int_fast64_t;

	using ::std::uint_fast8_t;
	using ::std::uint_fast16_t;
	using ::std::uint_fast32_t;
	using ::std::uint_fast64_t;

	using ::std::intmax_t;
	using ::std::intptr_t;

	using ::std::uintmax_t;
	using ::std::uintptr_t;
}
#endif

namespace pvc = ::pod_vs_class;

int run_test(int, char **) {
	::pvc::int8_t v_int8_t = 0;
	::pvc::int16_t v_int16_t = 1;
	::pvc::int32_t v_int32_t = 2;
	::pvc::int64_t v_int64_t = 3;

	::pvc::uint8_t v_uint8_t = 4;
	::pvc::uint16_t v_uint16_t = 5;
	::pvc::uint32_t v_uint32_t = 6;
	::pvc::uint64_t v_uint64_t = 7;

	::pvc::int_least8_t v_int_least8_t = 8;
	::pvc::int_least16_t v_int_least16_t = 9;
	::pvc::int_least32_t v_int_least32_t = 10;
	::pvc::int_least64_t v_int_least64_t = 11;

	::pvc::uint_least8_t v_uint_least8_t = 12;
	::pvc::uint_least16_t v_uint_least16_t = 13;
	::pvc::uint_least32_t v_uint_least32_t = 14;
	::pvc::uint_least64_t v_uint_least64_t = 15;

	::pvc::int_fast8_t v_int_fast8_t = 16;
	::pvc::int_fast16_t v_int_fast16_t = 17;
	::pvc::int_fast32_t v_int_fast32_t = 18;
	::pvc::int_fast64_t v_int_fast64_t = 19;

	::pvc::uint_fast8_t v_uint_fast8_t = 20;
	::pvc::uint_fast16_t v_uint_fast16_t = 21;
	::pvc::uint_fast32_t v_uint_fast32_t = 22;
	::pvc::uint_fast64_t v_uint_fast64_t = 23;

	::pvc::intmax_t v_intmax_t = 24;
	::pvc::intptr_t v_intptr_t = 25;

	::pvc::uintmax_t v_uintmax_t = 26;
	::pvc::uintptr_t v_uintptr_t = 27;

	::std::cin
		>> v_int8_t
		>> v_int16_t
		>> v_int32_t
		>> v_int64_t

		>> v_uint8_t
		>> v_uint16_t
		>> v_uint32_t
		>> v_uint64_t

		>> v_int_least8_t
		>> v_int_least16_t
		>> v_int_least32_t
		>> v_int_least64_t

		>> v_uint_least8_t
		>> v_uint_least16_t
		>> v_uint_least32_t
		>> v_uint_least64_t

		>> v_int_fast8_t
		>> v_int_fast16_t
		>> v_int_fast32_t
		>> v_int_fast64_t

		>> v_uint_fast8_t
		>> v_uint_fast16_t
		>> v_uint_fast32_t
		>> v_uint_fast64_t

		>> v_intmax_t
		>> v_intptr_t

		>> v_uintmax_t
		>> v_uintptr_t
	;

	::std::cout
		<< v_int8_t << '\n'
		<< v_int16_t << '\n'
		<< v_int32_t << '\n'
		<< v_int64_t << '\n'

		<< v_uint8_t << '\n'
		<< v_uint16_t << '\n'
		<< v_uint32_t << '\n'
		<< v_uint64_t << '\n'

		<< v_int_least8_t << '\n'
		<< v_int_least16_t << '\n'
		<< v_int_least32_t << '\n'
		<< v_int_least64_t << '\n'

		<< v_uint_least8_t << '\n'
		<< v_uint_least16_t << '\n'
		<< v_uint_least32_t << '\n'
		<< v_uint_least64_t << '\n'

		<< v_int_fast8_t << '\n'
		<< v_int_fast16_t << '\n'
		<< v_int_fast32_t << '\n'
		<< v_int_fast64_t << '\n'

		<< v_uint_fast8_t << '\n'
		<< v_uint_fast16_t << '\n'
		<< v_uint_fast32_t << '\n'
		<< v_uint_fast64_t << '\n'

		<< v_intmax_t << '\n'
		<< v_intptr_t << '\n'

		<< v_uintmax_t << '\n'
		<< v_uintptr_t << '\n'
	;

	return 0;	
}

int main(int argc, char ** argv) {
	return run_test(argc, argv);
}

