#pragma once

#include "ILexer.h"
#include "LowLexer.h"

namespace lng
{
namespace lowlexer
{

class LowLexerFacade : public ILexer
{

public:
	LowLexerFacade(std::string_view raw)
		: m_raw(raw), m_position(0)
	{}

	LowLexerFacade(std::string_view raw, size_t position)
		: m_raw(raw), m_position(position)
	{}

	token::OptToken Next() override;
	token::OptToken Peek() override;
	token::OptTokenList Peek(size_t numberOfTokens) override;

private:
	std::string_view m_raw;
	size_t m_position;

	void UpdatePositionAfterReadNextToken(const token::Token &readedToken);
};

} // Namespace lowlexer
} // Namespace lng