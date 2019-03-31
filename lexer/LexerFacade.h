#pragma once

#include "Lexer.h"

class LexerFacade
{

public:
	LexerFacade(std::string_view raw)
		: m_raw(raw), m_position(0)
	{}

	LexerFacade(std::string_view raw, size_t position)
		: m_raw(raw), m_position(position)
	{}

	lng::lexer::opt_token Next();

private:

	std::string_view m_raw;
	size_t m_position;
};