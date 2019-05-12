#pragma once

#include "Token.h"

namespace lng
{

class ILexer
{
public:
	virtual ~ILexer() = default;

	virtual token::OptToken Next() = 0;
	virtual token::OptToken Peek() = 0;
	virtual token::TokenList Peek(size_t numberOfTokens) = 0;
	virtual size_t NextPosition() = 0;
};

}