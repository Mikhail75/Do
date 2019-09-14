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
	TokenTypesList expected = { TT_NUMBER, TT_FULL_STOP, TT_NUMBER };

	auto predicate = [](const TokenList& tokens) {
		return NoSpacesBetweenTokens(tokens);
	};
	auto onSuccess = [](const TokenList& tokens) {
		auto position = tokens[0].data.position;
		auto value = tokens[0].data.value + "." + tokens[2].data.value;

		return Token{ TT_FLOAT_NUMBER, {position, value} };
	};

	return ReadTokenImpl(lowlexer, expected, { predicate }, onSuccess);
}

OptToken ReadMainFunction(ILexer &lowlexer)
{
	TokenTypesList expected = { TT_LEFT_BRACKET, TT_IDENTIFIER, TT_RIGHT_BRACKET, TT_IDENTIFIER, TT_LEFT_CURLY_BRACKET };

	auto predicate = [](const TokenList& tokens) {
		return MatchTokensByValues({ { tokens[1], "func" }, { tokens[3], "main" } });
	};
	auto onSuccess = [](const TokenList& tokens) {
		auto position = tokens[0].data.position;
		return Token{ TT_FUNCTION_MAIN, {position} };
	};

	return ReadTokenImpl(lowlexer, expected, { predicate }, onSuccess);
}

OptToken ReadFunction(ILexer &lowlexer)
{
	TokenTypesList expected = { TT_LEFT_BRACKET, TT_IDENTIFIER };

	auto predicate = [](const TokenList& tokens) {
		return MatchTokensByValues({ { tokens[1], "func" } });
	};
	auto onSuccess = [](const TokenList& tokens) {
		auto position = tokens[0].data.position;
		return Token{ TT_FUNCTION, {position} };
	};

	return ReadTokenImpl(lowlexer, expected, { predicate }, onSuccess);
}

} // namespace highlexer
} // namespace lng