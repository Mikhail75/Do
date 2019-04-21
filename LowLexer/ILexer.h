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
	virtual token::OptTokenList Peek(size_t numberOfTokens) = 0;
};

}