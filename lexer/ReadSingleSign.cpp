#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{
map<char, TokenType> singleSignToTokenMap{
	{'+', TT_PLUS},
	{'-', TT_MINUS},
	{'*', TT_ASTERISK},
	{'/', TT_SLASH},
	{'=', TT_EQUALS},
	{'%', TT_PERCENT},
	{'&', TT_AMPERSAND},
	{'|', TT_VERTICAL_LINE},
	{'!', TT_EXLAMATION_MARK},
	{'(', TT_LEFT_PARENTHESIS},
	{')', TT_RIGHT_PARENTHESIS},
	{'[', TT_LEFT_BRACKET},
	{']', TT_RIGHT_BRACKET},
	{'{', TT_LEFT_CURLY_BRACKET},
	{'}', TT_RIGHT_CURLY_BRACKET},
	{'<', TT_LESS_THAN},
	{'>', TT_GREATER_THAN},
	{',', TT_COMMA},
	{'.', TT_FULL_STOP},
};
} // End namespace

LexResult ReadSingleSign(string_view raw, size_t pos)
{
	if (auto it = singleSignToTokenMap.find(raw[pos]); it != singleSignToTokenMap.end())
	{
		return { Token{it->second},  ++pos };
	}
	return { nullopt, pos };
}

} // End namespace lexer
} // End namespace lng