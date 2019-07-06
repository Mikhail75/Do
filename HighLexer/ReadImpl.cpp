#include "stdafx.h"
#include "HighLexer.h"
#include "TokenUtils.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace highlexer
{

template <typename T>
bool MatchTokens(const TokenList &tokens, const vector<T> &expected, const function<bool(size_t index)> &predicate)
{
	if (tokens.size() != expected.size())
	{
		return false;
	}

	for (size_t i = 0; i < tokens.size(); ++i)
	{
		if (!predicate(i))
		{
			return false;
		}
	}

	return true;
}

bool MatchTokensByTypes(const TokenList &tokens, const TokenTypesList &expected)
{
	auto predicate = [&](size_t index) {
		return tokens[index].type == expected[index];
	};
	return MatchTokens(tokens, expected, predicate);
}

bool MatchTokensByValues(const TokenList &tokens, const vector<string> &expected)
{
	auto predicate = [&](size_t index) {
		return tokens[index].data.value == expected[index];
	};
	return MatchTokens(tokens, expected, predicate);
}

bool MatchTokensByValues(const vector<pair<Token, string>> &matches)
{
	TokenList tokens;
	vector<string> expected;

	for (const auto &match : matches)
	{
		tokens.push_back(match.first);
		expected.push_back(match.second);
	}

	return MatchTokensByValues(tokens, expected);
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