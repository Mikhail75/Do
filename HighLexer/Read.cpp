#include "stdafx.h"
#include "HighLexer.h"
#include "TokenUtils.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace highlexer
{

OptToken ReadFloatNumber(ILexer &lowlexer)
{
	auto tokens = lowlexer.Peek(3);
	TokenTypesList expected = { TT_NUMBER, TT_FULL_STOP, TT_NUMBER };

	if (MatchTokensByTypes(tokens, expected) && NoSpacesBetweenTokens(tokens))
	{
		auto position = tokens[0].data.position;
		auto value = tokens[0].data.value + "." + tokens[2].data.value;

		return Token{ TT_FLOAT_NUMBER, {position, value} };
	}

	return nullopt;
}

OptToken ReadMainFunction(ILexer &lowlexer)
{
	auto tokens = lowlexer.Peek(5);
	TokenTypesList expected = { TT_LEFT_BRACKET, TT_IDENTIFIER, TT_RIGHT_BRACKET, TT_IDENTIFIER, TT_LEFT_CURLY_BRACKET };

	if (MatchTokensByTypes(tokens, expected))
	{
		if (MatchTokensByValues({ { tokens[1], "func" }, { tokens[3], "main" } }))
		{
			auto position = tokens[0].data.position;
			return Token{ TT_FUNCTION_MAIN, {position} };
		}
	}

	return nullopt;
}

OptToken ReadFunction(ILexer &lowlexer)
{
	auto tokens = lowlexer.Peek(2);
	TokenTypesList expected = { TT_LEFT_BRACKET, TT_IDENTIFIER };

	if (MatchTokensByTypes(tokens, expected))
	{
		if (MatchTokensByValues({ { tokens[1], "func" } }))
		{
			auto position = tokens[0].data.position;
			return Token{ TT_FUNCTION, {position} };
		}
	}

	return nullopt;
}

} // namespace highlexer
} // namespace lng