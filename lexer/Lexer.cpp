#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

bool InRange(string_view raw, size_t pos)
{
	return pos < raw.size();
}

namespace
{
	vector<function<LexResult(string_view, size_t)>> readHandlers = {
		ReadSingleSign,
		ReadStringLiteral
	};
}

LexResult Read(string_view raw, size_t pos)
{
	pos = SkipSpaces(raw, pos);
	
	if (!InRange(raw, pos))
	{
		return { nullopt, pos};
	}

	for (const auto &handler : readHandlers)
	{
		if (auto [token, nextPos] = handler(raw, pos); token)
		{
			return { token,  nextPos };
		}
	}

	return { Token{ TT_ERROR } , pos};
}

} // End namespace lexer
} // End namespace lng