#pragma once

#include "Token.h"

namespace lng
{
namespace token
{

bool operator ==(const Token& a, const Token& b);
std::ostream &operator <<(std::ostream &stream, const Token &token);
std::ostream &operator <<(std::ostream &stream, const OptToken &token);

size_t GetTokenLength(const Token &token);

} // Namespace token
} // Namespace lng