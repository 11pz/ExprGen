#pragma once

template < class T >
class singleton {
public:
	static inline T *get( ) {
		static T s;
		return &s;
	}
protected:
	singleton( ) = default;
	virtual ~singleton( ) = default;

	singleton( const singleton & ) = delete;
	singleton &operator=( const singleton & ) = delete;

	singleton( singleton && ) = delete;
	singleton &operator=( singleton && ) = delete;
};