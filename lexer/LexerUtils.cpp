#include "stdafx.h"
#include "Lexer.h"
#include "LexerUtils.h"

using namespace std;

namespace lng
{
namespace lexer
{
bool operator ==(const Token& a, const Token& b)
{
	return a.type == b.type && a.data.value == b.data.value;
}

ostream &operator <<(ostream &stream, const Token &token)
{
	stream << "[Token] " << endl;
	stream << "type: " << token.type << "; value: ";

	token.data.value
		? stream << token.data.value.value() << "; "
		: stream << "nullopt; ";
	stream << endl;

	return stream;
}

ostream &operator <<(ostream &stream, const opt_token &token)
{
	token
		? stream << token.value()
		: stream << "[nullopt]";

	return stream;
}

} // End namespace lexer
} // End namespace lng
