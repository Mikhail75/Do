#include "stdafx.h"
#include "LowLexer.h"

using namespace std;

namespace lng
{
namespace lowlexer
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

} // Namespace lowlexer
} // Namespace lng
