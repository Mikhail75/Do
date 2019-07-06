#pragma once

#include <exception>
#include "MatchResult.h"

namespace lng
{
namespace parser
{

class MatchException : public std::exception
{
public:
	MatchException(const MatchError &matchError, std::string what = "Match token error")
		: std::exception(what.c_str()), m_matchError(matchError)
	{}

	~MatchException() noexcept override = default;

	MatchError GetMatchErrorInfo() const
	{
		return m_matchError;
	}
	
private:
	MatchError m_matchError;
};

} // namespace parser
} // namespace lng