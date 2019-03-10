#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{

vector<char> spaces = { ' ', '\t', '\n', '\r' };

}  

size_t SkipSpaces(string_view raw, size_t pos)
{
	auto isSpace = [&]() -> bool {
		return find(spaces.begin(), spaces.end(), raw[pos]) != spaces.end();
	};
	
	while (InRange(raw, pos) && isSpace())
	{
		++pos;
	}

	return pos;
}

} // End namespace lexer
} // End namespace lng