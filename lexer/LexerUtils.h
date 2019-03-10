#pragma once

namespace lng
{
namespace lexer
{

bool operator ==(const Token& a, const Token& b);
bool operator ==(const LexResult &a, const LexResult &b);

} // End namespace lexer
} // End namespace lng