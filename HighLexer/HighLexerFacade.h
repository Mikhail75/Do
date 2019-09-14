#pragma once

#include <deque>
#include "ILexer.h"
#include "HighLexer.h"

namespace lng
{
namespace highlexer
{

class CHighLexerFacade : public ILexer
{
public:
	CHighLexerFacade(ILexer &lowlexer)
		: m_lowlexer(lowlexer)
	{}

	token::OptToken Next() override;
	token::OptToken Peek() override;
	token::TokenList Peek(size_t numberOfTokens) override;
	size_t NextPosition() override;

private:
	ILexer &m_lowlexer;
	std::deque<token::Token> m_cache;

	token::OptToken ReadTokenImpl(size_t number = 0);
};

} // namespace highlexer
} // namespac