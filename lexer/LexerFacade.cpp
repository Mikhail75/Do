#include "stdafx.h"
#include "LexerFacade.h"
#include "LexerUtils.h"


using namespace std;

namespace lng
{
namespace lexer
{

opt_token LexerFacade::Next()
{
	if (auto token = ReadToken({ m_raw, m_position }))
	{
		UpdatePositionAfterReadNextToken(token.value());
		return token;
	}

	return nullopt;
}

opt_token LexerFacade::Peek()
{
	auto positionBeforePeek = m_position;
	auto token = Next();
	m_position = positionBeforePeek;

	return token;
}

opt_token_list LexerFacade::Peek(size_t numberOfTokens)
{
	auto positionBeforePeek = m_position;
	vector<Token> tokens;
	
	for (size_t i = 0; i < numberOfTokens; ++i)
	{
		if (auto nextToken = Next())
		{
			tokens.push_back(nextToken.value());
		}
	}
	m_position = positionBeforePeek;

	if (tokens.size() == numberOfTokens)
	{
		return opt_token_list{ tokens };
	}
	return nullopt;
}

void LexerFacade::UpdatePositionAfterReadNextToken(const Token &readedToken)
{
	size_t spacesCountBeforeToken = readedToken.data.position - m_position;
	size_t tokenLength = GetTokenLength(readedToken);

	m_position += spacesCountBeforeToken + tokenLength;
}

} // End namespace lexer
} // End namespace lng