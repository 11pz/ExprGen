#pragma once
#include "CExpression.hpp"

class CByteSwapTemplate final : public CExpression {
public:
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( _byteswap_uint64( std::int64_t( {} ) ) ) )", expr ) );
	}
};