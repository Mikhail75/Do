#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{
	map<char, TokenType> singleSignToToken {
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

opt_token ReadSingleSign(const ReadData &data)
{
	auto IsSingleSign = [](opt_char value) -> bool {
		return value && singleSignToToken.find(value.value()) != singleSignToToken.end();
	};

	if (auto singleSign = ReadIf(IsSingleSign, data); singleSign)
	{
		auto tokenType = singleSignToToken[singleSign.value()];
		return Token{ tokenType , { data.position} };
	}
	return nullopt;
}

opt_token ReadNumber(const ReadData &data)
{
	auto IsDigit = [](opt_char value) -> bool {
		return value >= '0'&& value <= '9';
	};

	if (Match(IsDigit, data))
	{
		auto value = ReadWhile(IsDigit, data);
		return Token{ TT_NUMBER, { data.position, value } };
	}
	return nullopt;
}

opt_token ReadStringLiteral(const ReadData &data)
{
	auto IsQuote = [](opt_char value) -> bool {
		return value == '\"' || value == '\'';
	};

	if (auto quote = ReadIf(IsQuote, data); quote)
	{
		if (auto literal = ReadBetween(quote.value(), data); literal)
		{
			return Token{ TT_STRING_LITERAL, { data.position, literal} };
		}
	}
	return nullopt;
}

} // End namespace lexer
} // End namespace lng