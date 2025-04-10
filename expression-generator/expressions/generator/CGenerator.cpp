#include "CGenerator.hpp"

std::pair < std::string, std::string > CExpressionGenerator::generate( std::uint32_t cycles ) {
	std::stack<CExpression *> stack;

	for ( std::uint32_t i {}; i != cycles; ++i ) {
		EType randomType = static_cast< EType >( utils::random( 0, EType::COUNT - 1 ) );
		CExpression *expr = createExpression( randomType );
		if ( expr )
			stack.push( expr );
	}

	return make( stack );
}