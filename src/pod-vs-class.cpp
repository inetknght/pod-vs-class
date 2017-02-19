#include <cstdint>
#include <type_traits>

///! \todo: move this to own header or something
#include <ios>

namespace pod_vs_class {
	template <typename t>
	class integer {
		using T = typename std::remove_const<t>::type;
		T value_;

		using integer_t = integer<t>;
	public:
		constexpr integer() = default;
		constexpr integer(const integer & copy_ctor) = default;
		constexpr integer(integer && move_ctor) = default;
		constexpr integer & operator=(const integer & copy_assign) = default;
		constexpr integer & operator=(integer && move_assign) = default;

		constexpr inline integer(T value) : value_(value) {}

		constexpr inline integer_t operator *(const integer_t & rhs) const { return value_ * rhs.value_; }
		constexpr inline integer_t operator /(const integer_t & rhs) const { return value_ / rhs.value_; }
		constexpr inline integer_t operator +(const integer_t & rhs) const { return value_ + rhs.value_; }
		constexpr inline integer_t operator -(const integer_t & rhs) const { return value_ - rhs.value_; }
		constexpr inline integer_t operator %(const integer_t & rhs) const { return value_ % rhs.value_; }

		constexpr inline integer_t operator +() const { return +value_; }
		constexpr inline integer_t operator -() const { return -value_; }

		constexpr inline integer_t & operator++() { ++value_; return *this; }
		constexpr inline integer_t & operator--() { --value_; return *this; }
		constexpr inline integer_t operator++(int) { return value_++; }
		constexpr inline integer_t operator--(int) { return value_++; }

		constexpr inline bool operator==(const integer_t & rhs) const { return value_ == rhs.value_; }
		constexpr inline bool operator!=(const integer_t & rhs) const { return value_ != rhs.value_; }
		constexpr inline bool operator>(const integer_t & rhs) const { return value_ > rhs.value_; }
		constexpr inline bool operator<(const integer_t & rhs) const { return value_ < rhs.value_; }
		constexpr inline bool operator>=(const integer_t & rhs) const { return value_ >= rhs.value_; }
		constexpr inline bool operator<=(const integer_t & rhs) const { return value_ <= rhs.value_; }

		constexpr inline integer_t operator!() const { return !value_; }

		template <typename T>
		friend ::std::ostream & operator<<(std::ostream & out, const integer<T> & v);
		template <typename T> friend ::std::istream & operator>>(std::istream & in, const integer<T> & v);
	};

template<typename T> inline std::ostream & operator<<(std::ostream & out, const integer<T> & v) { return out << v.value_; }
template<typename T> inline std::istream & operator>>(std::istream & in, integer<T> & v) { return in >> v.value_; }

using int8_t = integer<::std::int8_t>;
using int16_t = integer<::std::int16_t>;
using int32_t = integer<::std::int32_t>;
using int64_t = integer<::std::int64_t>;
using int_fast8_t = integer<::std::int_fast8_t>;
using int_fast16_t = integer<::std::int_fast16_t>;
using int_fast32_t = integer<::std::int_fast32_t>;
using int_fast64_t = integer<::std::int_fast64_t>;
using int_least8_t = integer<::std::int_least8_t>;
using int_least16_t = integer<::std::int_least16_t>;
using int_least32_t = integer<::std::int_least32_t>;
using int_least64_t = integer<::std::int_least64_t>;
using uint8_t = integer<::std::uint8_t>;
using uint16_t = integer<::std::uint16_t>;
using uint32_t = integer<::std::uint32_t>;
using uint64_t = integer<::std::uint64_t>;
using uint_fast8_t = integer<::std::uint_fast8_t>;
using uint_fast16_t = integer<::std::uint_fast16_t>;
using uint_fast32_t = integer<::std::uint_fast32_t>;
using uint_fast64_t = integer<::std::uint_fast64_t>;
using uint_least8_t = integer<::std::uint_least8_t>;
using uint_least16_t = integer<::std::uint_least16_t>;
using uint_least32_t = integer<::std::uint_least32_t>;
using uint_least64_t = integer<::std::uint_least64_t>;

using intmax_t = integer<::std::intmax_t>;
using uintmax_t = integer<::std::uintmax_t>;

template <typename T>
class ptr_t : public integer<T> {
public:
	using integer<T>::integer;
	
};

using intptr_t = ptr_t<::std::intptr_t>;
using uintptr_t = ptr_t<::std::uintptr_t>;

} // namespace pod_vs_class


