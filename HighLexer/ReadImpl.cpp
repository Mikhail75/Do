#include "stdafx.h"
#include "HighLexer.h"
#include "TokenUtils.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace highlexer
{

bool MatchTokensByTypes(const TokenList &tokens, const TokenTypesList &expected)
{
	if (tokens.size() != expected.size())
	{
		return false;
	}

	for (size_t i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i].type != expected[i])
		{
			return false;
		}
	}

	return true;
}

bool SpacesBetweenTokens(const TokenList &tokens)
{
	for (size_t i = 0; i < tokens.size() - 1; ++i)
	{
		auto currentTokenPosition = tokens[i].data.position;
		auto currentTokenLength = GetTokenLength(tokens[i]);
		auto nextTokenPosition = tokens[i + 1].data.position;

		bool spacesBetweenTokens = currentTokenPosition + currentTokenLength != nextTokenPosition;

		if (spacesBetweenTokens)
		{
			return true;
		}
	}

	return false;
}

bool NoSpacesBetweenTokens(const TokenList &tokens)
{
	return !SpacesBetweenTokens(tokens);
}

} // namespace highlexer
} // namespace lng