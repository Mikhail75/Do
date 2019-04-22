#include "stdafx.h"
#include "LowLexer.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace lowlexer
{

namespace
{

vector<function<OptToken(const ReadData&)>> readHandlers = {
	ReadSingleSign,
	ReadStringLiteral,
	ReadNumber,
	ReadIdentifier,
};

}

OptToken ReadToken(const ReadData &data)
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

} // Namespace lowlexer
} // Namespace lng