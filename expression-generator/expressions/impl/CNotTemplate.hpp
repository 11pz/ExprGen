#pragma once
#include "CExpression.hpp"

class CNotTemplate final : public CExpression {
public:
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( ~{} ) )", expr ) );
	}
};