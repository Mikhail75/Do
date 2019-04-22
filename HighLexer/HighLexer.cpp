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

vector<function<OptToken(const ILexer&)>> readHandlers = {

};

}

OptToken ReadToken(const ILexer &lowlexer)
{
	return nullopt;
}

} // namespace highlexer
} // namespace lng