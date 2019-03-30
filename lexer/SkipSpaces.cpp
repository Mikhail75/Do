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

size_t SkipSpaces(const ReadData &data)
{
	auto raw = data.raw;
	auto position = data.position;

	auto isSpace = [&](opt_char value) -> bool {
		return find(spaces.begin(), spaces.end(), raw[position]) != spaces.end();
	};
	
	while (Match(isSpace, { raw, position }))
	{
		++position;
	}

	return position;
}

} // End namespace lexer
} // End namespace lng