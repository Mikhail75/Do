#pragma once

#include <string>
#include <vector>
#include <optional>

namespace lng
{
namespace token
{

enum TokenType
{
	TT_END = 0,
	TT_ERROR,
	TT_NUMBER,
	TT_IDENTIFIER,
	TT_STRING_LITERAL,
	TT_PLUS,                // '+'
	TT_MINUS,               // '-'
	TT_ASTERISK,            // '*'
	TT_SLASH,               // '/'
	TT_EQUALS,              // '='
	TT_PERCENT,             // '%'
	TT_AMPERSAND,           // '&'
	TT_VERTICAL_LINE,       // '|'
	TT_EXLAMATION_MARK,     // '!' 
	TT_LEFT_PARENTHESIS,    // '('
	TT_RIGHT_PARENTHESIS,   // ')'
	TT_LEFT_BRACKET,        // '['
	TT_RIGHT_BRACKET,       // ']'
	TT_LEFT_CURLY_BRACKET,  // '{'
	TT_RIGHT_CURLY_BRACKET, // '}'
	TT_LESS_THAN,           // '<'
	TT_GREATER_THAN,        // '>'
	TT_COMMA,               // ','
	TT_FULL_STOP,           // '.' 

	TT_FLOAT_NUMBER,

	TT_FUNCTION_MAIN,       // Begin of function "main"
	TT_FUNCTION,			// Begin of function
};

struct TokenData
{
	size_t position;
	std::string value;
};

struct Token
{
	TokenType type = TT_END;
	TokenData data;
};

using OptToken = std::optional<Token>;
using TokenList = std::vector<Token>;
using OptTokenList = std::optional<TokenList>;

} // Namespace token
} // Namespace lng