#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

namespace
{

vector<ReadTokenFunc> readHandlers = {
	ReadSingleSign,
	ReadStringLiteral,
	ReadNumber,
	ReadIdentifier,
};

}

opt_token ReadToken(const ReadData &data)
{
	auto pos = SkipSpaces(data);
	
	if (!InRange({ data.raw, pos }))
	{
		return nullopt;
	}
	
	for (const auto &handler : readHandlers)
	{
		if (auto token = handler({ data.raw, pos }))
		{
			return token;
		}
	}

	return Token{ TT_ERROR };
}

} // End namespace lexer
} // End namespace lng