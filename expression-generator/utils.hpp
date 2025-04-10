#pragma once

namespace utils {
	template < class T >
	concept arithmetic = requires( T x ) {
		x++, x--,
			x += x, x -= x, x *= x, x /= x, x %= x,
			x ^= x, x |= x, x &= x, ~x,
			x + x, x - x, x *x, x / x, x %x,
			x ^x, x | x, x &x, x << x, x >> x,
			x >>= x, x <<= x;
	};

	template < class T >
	concept function_cast_available = requires( T x ) {
		decltype( x )( 0 );
	};

	template < class T = unsigned char > requires( arithmetic< T > &&function_cast_available< T > )
	[[ nodiscard ]] inline T random( T min = T( 0 ), T max = T( -1 ) ) {
		return __rdtsc( ) % ( max - min + 1 ) + min;
	}
}