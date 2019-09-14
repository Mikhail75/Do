#include "MockLowLexer.h"

using namespace std;

namespace lng
{

CMockLowLexer::CMockLowLexer(const token::TokenList & tokens)
	: m_tokens(tokens)
{
}

token::OptToken CMockLowLexer::Next()
{
	if (auto token = NextImpl())
	{
		++m_position;
		return token;
	}
	return nullopt;
}

token::OptToken CMockLowLexer::Peek()
{
	return NextImpl();
}

token::TokenList CMockLowLexer::Peek(size_t numberOfTokens)
{
	auto positionBeforePeek = m_position;
	token::TokenList tokens;

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

token::OptToken CMockLowLexer::NextImpl()
{
	if (m_position < m_tokens.size())
	{
		return m_tokens[m_position];
	}
	return nullopt;
}

}