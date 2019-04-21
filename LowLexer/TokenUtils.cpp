#include "stdafx.h"
#include "LowLexer.h"
#include "TokenUtils.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace token
{

bool operator ==(const Token& a, const Token& b)
{
	return a.type == b.type && a.data.position == b.data.position && a.data.value == b.data.value;
}

ostream &operator <<(ostream &stream, const Token &token)
{
	stream << "[Token] " << endl;
	stream << "type: " << token.type << "; position: " << token.data.position;
	stream << "; value: " << token.data.value << endl;

	return stream;
}

ostream &operator <<(ostream &stream, const OptToken &token)
{
	token
		? stream << token.value()
		: stream << "[nullopt]";

	return stream;
}

size_t GetTokenLength(const Token &token)
{
	size_t length = token.data.value.length();

	if (token.type == TT_STRING_LITERAL)
	{
		length += 2; // Quotes
	}

	return length;
}

} // Namespace token
} // Namespace lng
