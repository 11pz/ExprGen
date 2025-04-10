#pragma once
#include "singleton.hpp"
#include "string"
#include <format>
#include <intrin.h>

class CExpression {
private:
	std::uint64_t m_value {};
public:
	CExpression( ) {
		_rdseed64_step( &m_value );
	}

	CExpression( std::uint64_t value ) : m_value( value ) { }

	virtual void apply( std::string &s ) = 0;

	std::uint64_t value( ) const { return m_value; }
};
