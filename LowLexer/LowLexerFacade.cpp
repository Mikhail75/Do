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
	if (auto token = ReadToken({ m_raw, m_position }))
	{
		UpdatePositionAfterReadNextToken(token.value());
		return token;
	}

	return nullopt;
}

OptToken CLowLexerFacade::Peek()
{
	auto positionBeforePeek = m_position;
	auto token = Next();
	m_position = positionBeforePeek;

	return token;
}

TokenList CLowLexerFacade::Peek(size_t numberOfTokens)
{
	auto positionBeforePeek = m_position;
	TokenList tokens;
	
	for (size_t i = 0; i < numberOfTokens; ++i)
	{
		if (auto nextToken = Next())
		{
			tokens.push_back(nextToken.value());
		}
	}
	m_position = positionBeforePeek;

	return tokens;
}

size_t CLowLexerFacade::NextPosition()
{
	return SkipSpaces({ m_raw, m_position });
}

void CLowLexerFacade::UpdatePositionAfterReadNextToken(const Token &readedToken)
{
	size_t spacesCountBeforeToken = readedToken.data.position - m_position;
	size_t tokenLength = GetTokenLength(readedToken);

	m_position += spacesCountBeforeToken + tokenLength;
}

} // Namespace lowlexer
} // Namespace lng