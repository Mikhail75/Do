#include "stdafx.h"
#include "HighLexerFacade.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace highlexer
{

OptToken CHighLexerFacade::Next()
{
	if (auto token = ReadTokenImpl())
	{
		m_cache.pop_front();
		return token;
	}

	return nullopt;
}

OptToken CHighLexerFacade::Peek()
{
	return ReadTokenImpl();
}

TokenList CHighLexerFacade::Peek(size_t numberOfTokens)
{
	TokenList tokens;

	for (size_t i = 0; i < numberOfTokens; ++i)
	{
		if (auto token = ReadTokenImpl(i))
		{
			tokens.push_back(token.value());
			continue;
		}

		break;
	}

	return tokens;
}

size_t CHighLexerFacade::NextPosition()
{
	return size_t();
}

OptToken CHighLexerFacade::ReadTokenImpl(size_t number)
{
	if (number < m_cache.size())
	{
		return m_cache[number];
	}

	if (auto token = ReadToken(m_lowlexer))
	{
		m_cache.push_back(token.value());
		return m_cache.back();
	}

	return nullopt;
}

} // namespace highlexer
} // namespac