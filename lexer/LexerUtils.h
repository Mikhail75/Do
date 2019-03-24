#pragma once

namespace lng
{
namespace lexer
{

bool operator ==(const Token& a, const Token& b);
bool operator ==(const LexResult &a, const LexResult &b);

std::ostream& operator <<(std::ostream &stream, const LexResult &lexResult);

} // End namespace lexer
} // End namespace lng