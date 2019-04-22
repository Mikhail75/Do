#pragma once

#include "Token.h"
#include "ILexer.h"

namespace lng
{
namespace highlexer
{
	
token::OptToken ReadToken(const ILexer &lowlexer);

} // namespace highlexer
} // namespace lng