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

} // namespace highlexer
} // namespace lng