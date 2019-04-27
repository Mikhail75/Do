#pragma once

#include "Token.h"
#include "ILexer.h"

namespace lng
{
namespace highlexer
{

using TokenTypesList = std::vector<token::TokenType>;

bool MatchTokensByTypes(const token::TokenList &tokens, const TokenTypesList &expected);
bool SpacesBetweenTokens(const token::TokenList &tokens);
bool NoSpacesBetweenTokens(const token::TokenList &tokens);

token::OptToken ReadFloatNumber(ILexer &lowlexer);

token::OptToken ReadToken(ILexer &lowlexer);

} // namespace highlexer
} // namespace lng