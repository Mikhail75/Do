#pragma once

#include "Token.h"
#include "LexerTypes.h"

namespace lng
{
namespace lexer
{

bool operator ==(const Token& a, const Token& b);
std::ostream &operator <<(std::ostream &stream, const Token &token);
std::ostream &operator <<(std::ostream &stream, const opt_token &token);

} // End namespace lexer
} // End namespace lng