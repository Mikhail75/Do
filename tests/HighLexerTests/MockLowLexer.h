#pragma once

#include "ILexer.h"

namespace lng
{

class CMockLowLexer : public ILexer
{
public:
	CMockLowLexer(const token::TokenList& tokens);

	token::OptToken Next() override;
	token::OptToken Peek() override;
	token::OptTokenList Peek(size_t numberOfTokens) override;

private:
	token::OptToken NextImpl();

	token::TokenList m_tokens;
	size_t m_position = 0;
};

}

