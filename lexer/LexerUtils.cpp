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

std::ostream &operator <<(std::ostream &stream, const LexResult &lexResult)
{
	stream  << "Token: [Token]" << std::endl;
	stream  << "Next position: " << lexResult.second << std::endl;
	
	return stream;
}

} // End namespace lexer
} // End namespace lng
