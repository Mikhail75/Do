#pragma once

#include "ILexer.h"
#include "Lexer.h"

namespace lng
{
namespace lexer
{

class LexerFacade : public ILexer
{

public:
	LexerFacade(std::string_view raw)
		: m_raw(raw), m_position(0)
	{}

	LexerFacade(std::string_view raw, size_t position)
		: m_raw(raw), m_position(position)
	{}

	opt_token Next() override;
	opt_token Peek() override;
	opt_token_list Peek(size_t numberOfTokens) override;

private:
	std::string_view m_raw;
	size_t m_position;

	void UpdatePositionAfterReadNextToken(const Token &readedToken);
};

} // End namespace lexer
} // End namespace lng