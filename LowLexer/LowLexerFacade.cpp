#include "stdafx.h"
#include "LowLexerFacade.h"
#include "TokenUtils.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace lowlexer
{

OptToken CLowLexerFacade::Next()
{
	if (auto token = ReadTokenImpl(m_position))
	{
		m_cache->Remove(m_position);
		m_position = PositionAfterToken(token);

		return token;
	}

	return nullopt;
}

OptToken CLowLexerFacade::Peek()
{
	if (auto token = ReadTokenImpl(m_position))
	{
		m_cache->Add(m_position, token);
		return token;
	}

	return nullopt;
}

TokenList CLowLexerFacade::Peek(size_t numberOfTokens)
{
	auto position = m_position;
	TokenList tokens;
	
	for (size_t i = 0; i < numberOfTokens; ++i)
	{
		if (auto token = ReadTokenImpl(position))
		{
			m_cache->Add(position, token);
			position = PositionAfterToken(token);

			tokens.push_back(token.value());
		}
	}

	return tokens;
}

size_t CLowLexerFacade::NextPosition()
{
	return SkipSpaces({ m_raw, m_position });
}

OptToken CLowLexerFacade::ReadTokenImpl(size_t position)
{
	if (auto token = m_cache->Read(position))
	{
		return token;
	}

	if (auto token = ReadToken({ m_raw, position }))
	{
		return token;
	}

	return nullopt;
}

size_t CLowLexerFacade::PositionAfterToken(const OptToken &optToken) const
{
	if (!optToken)
	{
		return m_position;
	}

	auto token = optToken.value();

	size_t spaceBeforeToken = token.data.position - m_position;
	size_t tokenLength = GetTokenLength(token);

	return m_position + spaceBeforeToken + tokenLength;
}

} // Namespace lowlexer
} // Namespace lng