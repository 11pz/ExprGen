#pragma once
#include "CExpression.hpp"

class CRotlTemplate final : public CExpression {
public:
	CRotlTemplate( ) : CExpression( ) { }
	CRotlTemplate( std::uint64_t value ) : CExpression( value ) { }
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( _rotl64( std::int64_t( {} ), {} ) ) )", expr, std::to_string( std::int32_t( value( ) ) ) ) );
	}
};

class CRotrTemplate final : public CExpression {
public:
	CRotrTemplate( ) : CExpression( ) { }
	CRotrTemplate( std::uint64_t value ) : CExpression( value ) { }
	void apply( std::string &expr ) override {
		expr.assign( std::format( "( std::int64_t( _rotr64( std::int64_t( {} ), {} ) ) )", expr, std::to_string( std::int32_t( value( ) ) ) ) );
	}
};