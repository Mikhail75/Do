#include "stdafx.h"
#include "Lexer.h"
#include "LexerUtils.h"

namespace lng
{
namespace lexer
{
bool operator ==(const Token& a, const Token& b)
{
	return a.type == b.type && a.value == b.value;
}

bool operator ==(const LexResult &a, const LexResult &b)
{
	return a.first == b.first && a.second == b.second;
}

} // End namespace lexer
} // End namespace lng
