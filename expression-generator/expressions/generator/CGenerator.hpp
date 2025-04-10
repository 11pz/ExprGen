#pragma once
#include <stack>
#include "CExpression.hpp"
#include "CXorTemplate.hpp"
#include "CByteSwapTemplate.hpp"
#include "CNegTemplate.hpp"
#include "CRotTemplate.hpp"
#include "CNotTemplate.hpp"
#include "CAddSubTemplate.hpp"
#include "utils.hpp"

class CExpressionGenerator final : public singleton<CExpressionGenerator> {
private:
    enum EType {
        XOR = 1,
        BYTESWAP = 2,
        NEGATIVE = 3,
        ROTL = 4,
        ROTR = 5,
        NOT = 6,
        ADD = 7,
        SUB = 8,
        COUNT
    };

    [[ nodiscard ]] CExpression *createExpression( EType type ) {
        switch ( type ) {
        case EType::XOR: return new CXorTemplate( );
        case EType::BYTESWAP: return new CByteSwapTemplate( );
        case EType::NEGATIVE: return new CNegTemplate( );
        case EType::ROTL: return new CRotlTemplate( );
        case EType::ROTR: return new CRotrTemplate( );
        case EType::NOT: return new CNotTemplate( );
        case EType::ADD: return new CAddTemplate( );
        case EType::SUB: return new CSubTemplate( );
        default: return nullptr;
        }
    }

    std::pair < std::string, std::string > make( std::stack< CExpression * > &stack ) {
        std::string encryption( "enc" ), decryption( "dec" );
        std::stack < CExpression * > decryption_stack;

        while ( !stack.empty( ) ) {
            auto expr = stack.top( );
            expr->apply( encryption );
            decryption_stack.push( expr );
            stack.pop( );
        }

        while ( !decryption_stack.empty( ) ) {
            auto expr = decryption_stack.top( );

            if ( dynamic_cast< CRotlTemplate * >( expr ) )
                expr = new CRotrTemplate( std::int32_t( expr->value( ) ) );
            else if ( dynamic_cast< CRotrTemplate * >( expr ) )
                expr = new CRotlTemplate( std::int32_t( expr->value( ) ) );

            if ( dynamic_cast< CAddTemplate * >( expr ) )
                expr = new CSubTemplate( expr->value( ) );
            else if ( dynamic_cast< CSubTemplate * >( expr ) )
                expr = new CAddTemplate( expr->value( ) );

            expr->apply( decryption );
            decryption_stack.pop( );
        }

        return { encryption, decryption };
    }
public:
    std::pair < std::string, std::string > generate( std::uint32_t cycles );
};