#include "CGenerator.hpp"

int main( ) {
	std::uint32_t amount {}, length {};
	
	printf( "Enter amount of expressions: " );
	scanf_s( "%d", &amount );
	printf( "Enter length of expressions: " );
	scanf_s( "%d", &length );
	
	auto instance = CExpressionGenerator::get( );

	for ( std::uint32_t i {}; i < amount; i++ ) {
		auto [encryption, decryption] = instance->generate( length );
	
		printf("#define ENCRYPT%d( enc ) %s\n#define DECRYPT%d( dec ) %s\n", i, encryption.c_str(), i, decryption.c_str());
	}
}