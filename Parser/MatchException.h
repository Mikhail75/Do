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
	MatchException(const MatchErrorInfo &matchErrorInfo, std::string what = "Match token error")
		: std::exception(what.c_str()), m_matchErrorInfo(matchErrorInfo)
	{}

	~MatchException() noexcept override = default;

	MatchErrorInfo GetMatchErrorInfo() const
	{
		return m_matchErrorInfo;
	}
	
private:
	MatchErrorInfo m_matchErrorInfo;
};

} // namespace parser
} // namespace lng