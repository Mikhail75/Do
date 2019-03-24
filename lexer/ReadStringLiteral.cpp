#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{
optional<char> IsQuote(std::string_view raw, size_t pos)
{
	auto ch = raw[pos];
	
	if (ch == '\"' || ch == '\'')
	{
		return ch;
	}
	return nullopt;
}
} // End namespace

LexResult ReadStringLiteral(std::string_view raw, size_t pos)
{
	if (auto quote = IsQuote(raw, pos); quote)
	{
		string literal;
		auto next = pos + 1;

		while(InRange(raw, next))
		{
			if (raw[next] == quote)
			{
				return { Token{TT_STRING_LITERAL, literal}, ++next };
			}
			literal += raw[next++];
		}
	}

	return { nullopt, pos };
}

} // End namespace lexer
} // End namespace lng