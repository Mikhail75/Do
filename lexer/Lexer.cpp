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
};

}

opt_token ReadToken(const ReadData &data)
{
	if (!InRange(data))
	{
		return nullopt;
	}
	
	auto pos = SkipSpaces(data);
	
	for (const auto &handler : readHandlers)
	{
		if (auto token = handler({ data.raw, pos }); token)
		{
			return token;
		}
	}

	return Token{ TT_ERROR };
}

} // End namespace lexer
} // End namespace lng