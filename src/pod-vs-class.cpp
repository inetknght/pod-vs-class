#include <cstdint>
#include <type_traits>

///! \todo: move this to own header or something
#include <ios>

namespace pod_vs_class {
	template <typename t>
	class alignas(t) integer {
		using T = typename std::remove_const<t>::type;
		T value_;

		using integer_t = integer<t>;
	public:
		using underlying_type = T;

		constexpr integer() = default;
		constexpr integer(const integer & copy_ctor) = default;
		constexpr integer(integer && move_ctor) = default;
		constexpr integer & operator=(const integer & copy_assign) = default;
		constexpr integer & operator=(integer && move_assign) = default;

		constexpr inline integer(T value) : value_(value) {}
		constexpr inline operator bool() const { return value_; }

		constexpr inline integer_t operator *(const integer_t & rhs) const { return value_ * rhs.value_; }
		constexpr inline integer_t operator /(const integer_t & rhs) const { return value_ / rhs.value_; }
		constexpr inline integer_t operator +(const integer_t & rhs) const { return value_ + rhs.value_; }
		constexpr inline integer_t operator -(const integer_t & rhs) const { return value_ - rhs.value_; }
		constexpr inline integer_t operator %(const integer_t & rhs) const { return value_ % rhs.value_; }
		constexpr inline integer_t operator &(const integer_t & rhs) const { return value_ & rhs.value_; }
		constexpr inline integer_t operator |(const integer_t & rhs) const { return value_ | rhs.value_; }
		constexpr inline integer_t operator ^(const integer_t & rhs) const { return value_ ^ rhs.value_; }
		constexpr inline integer_t operator <<(const integer_t & rhs) const { return value_ << rhs.value_; }
		constexpr inline integer_t operator >>(const integer_t & rhs) const { return value_ >> rhs.value_; }

		constexpr inline integer_t operator +() const { return +value_; }
		constexpr inline integer_t operator -() const { return -value_; }
		constexpr inline integer_t operator ~() const { return ~value_; }

		constexpr inline integer_t & operator *=(const integer_t & rhs) { value_ *= rhs.value_; return *this; }
		constexpr inline integer_t & operator /=(const integer_t & rhs) { value_ /= rhs.value_; return *this; }
		constexpr inline integer_t & operator +=(const integer_t & rhs) { value_ += rhs.value_; return *this; }
		constexpr inline integer_t & operator -=(const integer_t & rhs) { value_ -= rhs.value_; return *this; }
		constexpr inline integer_t & operator %=(const integer_t & rhs) { value_ %= rhs.value_; return *this; }
		constexpr inline integer_t & operator &=(const integer_t & rhs) { value_ &= rhs.value_; return *this; }
		constexpr inline integer_t & operator |=(const integer_t & rhs) { value_ |= rhs.value_; return *this; }
		constexpr inline integer_t & operator ^=(const integer_t & rhs) { value_ ^= rhs.value_; return *this; }
		constexpr inline integer_t & operator <<=(const integer_t & rhs) { value_ <<= rhs.value_; return *this; }
		constexpr inline integer_t & operator >>=(const integer_t & rhs) { value_ >>= rhs.value_; return *this; }

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

		template <typename T>
		friend ::std::istream & operator>>(std::istream & in, integer<T> & v);
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

static_assert(sizeof(int8_t) == sizeof(::std::int8_t), "sizeof(pod_vs_class::int8_t) != sizeof(::std::int8_t)");
static_assert(sizeof(int16_t) == sizeof(::std::int16_t), "sizeof(pod_vs_class::int16_t) != sizeof(::std::int16_t)");
static_assert(sizeof(int32_t) == sizeof(::std::int32_t), "sizeof(pod_vs_class::int32_t) != sizeof(::std::int32_t)");
static_assert(sizeof(int64_t) == sizeof(::std::int64_t), "sizeof(pod_vs_class::int64_t) != sizeof(::std::int64_t)");
static_assert(sizeof(int_fast8_t) == sizeof(::std::int_fast8_t), "sizeof(pod_vs_class::int_fast8_t) != sizeof(::std::int_fast8_t)");
static_assert(sizeof(int_fast16_t) == sizeof(::std::int_fast16_t), "sizeof(pod_vs_class::int_fast16_t) != sizeof(::std::int_fast16_t)");
static_assert(sizeof(int_fast32_t) == sizeof(::std::int_fast32_t), "sizeof(pod_vs_class::int_fast32_t) != sizeof(::std::int_fast32_t)");
static_assert(sizeof(int_fast64_t) == sizeof(::std::int_fast64_t), "sizeof(pod_vs_class::int_fast64_t) != sizeof(::std::int_fast64_t)");
static_assert(sizeof(int_least8_t) == sizeof(::std::int_least8_t), "sizeof(pod_vs_class::int_least8_t) != sizeof(::std::int_least8_t)");
static_assert(sizeof(int_least16_t) == sizeof(::std::int_least16_t), "sizeof(pod_vs_class::int_least16_t) != sizeof(::std::int_least16_t)");
static_assert(sizeof(int_least32_t) == sizeof(::std::int_least32_t), "sizeof(pod_vs_class::int_least32_t) != sizeof(::std::int_least32_t)");
static_assert(sizeof(int_least64_t) == sizeof(::std::int_least64_t), "sizeof(pod_vs_class::int_least64_t) != sizeof(::std::int_least64_t)");

static_assert(sizeof(uint8_t) == sizeof(::std::uint8_t), "sizeof(pod_vs_class::uint8_t) != sizeof(::std::uint8_t)");
static_assert(sizeof(uint16_t) == sizeof(::std::uint16_t), "sizeof(pod_vs_class::uint16_t) != sizeof(::std::uint16_t)");
static_assert(sizeof(uint32_t) == sizeof(::std::uint32_t), "sizeof(pod_vs_class::uint32_t) != sizeof(::std::uint32_t)");
static_assert(sizeof(uint64_t) == sizeof(::std::uint64_t), "sizeof(pod_vs_class::uint64_t) != sizeof(::std::uint64_t)");
static_assert(sizeof(uint_fast8_t) == sizeof(::std::uint_fast8_t), "sizeof(pod_vs_class::uint_fast8_t) != sizeof(::std::uint_fast8_t)");
static_assert(sizeof(uint_fast16_t) == sizeof(::std::uint_fast16_t), "sizeof(pod_vs_class::uint_fast16_t) != sizeof(::std::uint_fast16_t)");
static_assert(sizeof(uint_fast32_t) == sizeof(::std::uint_fast32_t), "sizeof(pod_vs_class::uint_fast32_t) != sizeof(::std::uint_fast32_t)");
static_assert(sizeof(uint_fast64_t) == sizeof(::std::uint_fast64_t), "sizeof(pod_vs_class::uint_fast64_t) != sizeof(::std::uint_fast64_t)");
static_assert(sizeof(uint_least8_t) == sizeof(::std::uint_least8_t), "sizeof(pod_vs_class::uint_least8_t) != sizeof(::std::uint_least8_t)");
static_assert(sizeof(uint_least16_t) == sizeof(::std::uint_least16_t), "sizeof(pod_vs_class::uint_least16_t) != sizeof(::std::uint_least16_t)");
static_assert(sizeof(uint_least32_t) == sizeof(::std::uint_least32_t), "sizeof(pod_vs_class::uint_least32_t) != sizeof(::std::uint_least32_t)");
static_assert(sizeof(uint_least64_t) == sizeof(::std::uint_least64_t), "sizeof(pod_vs_class::uint_least64_t) != sizeof(::std::uint_least64_t)");

static_assert(sizeof(intptr_t) == sizeof(::std::intptr_t), "sizeof(pod_vs_class::intptr_t) != sizeof(::std::intptr_t)");
static_assert(sizeof(uintptr_t) == sizeof(::std::uintptr_t), "sizeof(pod_vs_class::uintptr_t) != sizeof(::std::uintptr_t)");

} // namespace pod_vs_class


