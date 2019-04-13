#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{

map<char, TokenType> SINGLE_SIGN_TO_TOKEN {
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

const std::vector<char> IDENTIFIER_CHARSET {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v','w','x','y','z','_','0','1','2','3','4','5','6',
	'7','8','9','0'
};

bool IsSingleSign(opt_char value)
{
	return value && SINGLE_SIGN_TO_TOKEN.find(value.value()) != SINGLE_SIGN_TO_TOKEN.end();
}

bool IsDigit(opt_char value)
{
	return value >= '0' && value <= '9';
}

bool IsIdentifierChar(opt_char value)
{
	return find(IDENTIFIER_CHARSET.begin(), IDENTIFIER_CHARSET.end(), value.value()) != IDENTIFIER_CHARSET.end();
}

bool IsQuote(opt_char value)
{
	return value == '\"' || value == '\'';
}

} // End namespace

opt_token ReadSingleSign(const ReadData &data)
{
	if (auto singleSign = ReadIf(IsSingleSign, data))
	{
		auto tokenType = SINGLE_SIGN_TO_TOKEN[singleSign.value()];
		return Token{ tokenType , { data.position} };
	}
	return nullopt;
}

opt_token ReadNumber(const ReadData &data)
{
	if (Match(IsDigit, data))
	{
		auto value = ReadWhile(IsDigit, data);
		return Token{ TT_NUMBER, { data.position, value } };
	}
	return nullopt;
}

opt_token ReadIdentifier(const ReadData &data)
{
	if (Match(IsIdentifierChar, data) && !Match(IsDigit, data))
	{
		auto value = ReadWhile(IsIdentifierChar, data);
		return Token{ TT_IDENTIFIER, { data.position, value } };
	}
	return nullopt;
}

opt_token ReadStringLiteral(const ReadData &data)
{
	if (auto quote = ReadIf(IsQuote, data))
	{
		if (auto literal = ReadBetween(quote.value(), data))
		{
			return Token{ TT_STRING_LITERAL, { data.position, literal} };
		}
	}
	return nullopt;
}

} // End namespace lexer
} // End namespace lng