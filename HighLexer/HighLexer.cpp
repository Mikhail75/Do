#include "stdafx.h"
#include "HighLexer.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace highlexer
{

namespace
{

vector<function<OptToken(ILexer&)>> handlers = {
	ReadFloatNumber,
	ReadMainFunction,
	ReadFunction,
};

}

OptToken ReadToken(ILexer &lowlexer)
{
	for (const auto &handler : handlers)
	{
		if (auto token = handler(lowlexer))
		{
			return token;
		}
	}

	return lowlexer.Next();
}

} // namespace highlexer
} // namespace lng