#pragma once
#include "CExpression.hpp"

class CXorTemplate final : public CExpression {
public:
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( {} ) ^ {}LL )", expr, std::to_string( value( ) ) ) );
	}
};