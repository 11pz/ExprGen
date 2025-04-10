#pragma once
#include "CExpression.hpp"

class CAddTemplate final : public CExpression {
public:
	CAddTemplate( ) : CExpression( ) { }
	CAddTemplate( std::uint64_t value ) : CExpression( value ) { }
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( std::int64_t( {} ) + {}LL ) )", expr, std::to_string( value( ) ) ) );
	}
};

class CSubTemplate final : public CExpression {
public:
	CSubTemplate( ) : CExpression( ) { }
	CSubTemplate( std::uint64_t value ) : CExpression( value ) { }
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( std::int64_t( {} ) - {}LL ) )", expr, std::to_string( value( ) ) ) );
	}
};