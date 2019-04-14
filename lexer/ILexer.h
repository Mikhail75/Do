#pragma once

#include <vector>
#include "LexerTypes.h"

namespace lng
{
namespace lexer
{

class ILexer
{
public:
	virtual ~ILexer() = default;

	virtual opt_token Next() = 0;
	virtual opt_token Peek() = 0;
	virtual opt_token_list Peek(size_t numberOfTokens) = 0;
};

} // End namespace lexer
} // End namespace lng