#pragma once

#include <optional>
#include "Token.h"

namespace lng
{
namespace parser
{

struct MatchError
{
	MatchError(size_t position_, token::TokenType expected_, token::TokenType current_)
		: position(position_), expected(expected_), current(current_)
	{}

	size_t position;
	token::TokenType expected;
	token::TokenType current;
};

using OptMatchError = std::optional<MatchError>;

class MatchResult
{
public:
	MatchResult()
	{}

	MatchResult(const MatchError &matchError)
		: m_matchError(matchError)
	{}

	OptMatchError GetMatchError() const
	{
		return m_matchError;
	}

	operator bool() const
	{
		return m_matchError ? false : true;
	}

private:
	OptMatchError m_matchError;
};

} // namespace parser
} // namespace lng