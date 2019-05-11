#pragma once

#include <optional>
#include "Token.h"

namespace lng
{
namespace parser
{

struct MatchErrorInfo
{
	MatchErrorInfo(token::TokenType expected_, token::TokenType current_, token::Token wrongToken_)
		: expected(expected_), current(current_), wrongToken(wrongToken_)
	{}

	token::TokenType expected;
	token::TokenType current;
	token::Token wrongToken;
};

using OptMatchErrorInfo = std::optional<MatchErrorInfo>;

class MatchResult
{
public:
	MatchResult()
	{}

	MatchResult(const MatchErrorInfo& errorInfo)
		: m_errorInfo(errorInfo)
	{}

	OptMatchErrorInfo ErrorInfo() const
	{
		return m_errorInfo;
	}

	operator bool() const
	{
		return m_errorInfo ? false : true;
	}

private:
	OptMatchErrorInfo m_errorInfo;
};

} // namespace parser
} // namespace lng