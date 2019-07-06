#pragma once

#include "Token.h"
#include "ILexer.h"

namespace lng
{
namespace highlexer
{

using TokenTypesList = std::vector<token::TokenType>;

bool MatchTokensByTypes(const token::TokenList &tokens, const TokenTypesList &expected);
bool MatchTokensByValues(const token::TokenList &tokens, const std::vector<std::string> &expected);
bool MatchTokensByValues(const std::vector<std::pair<token::Token, std::string>> &matches);
bool SpacesBetweenTokens(const token::TokenList &tokens);
bool NoSpacesBetweenTokens(const token::TokenList &tokens);

token::OptToken ReadFloatNumber(ILexer &lowlexer);
token::OptToken ReadMainFunction(ILexer &lowlexer);

token::OptToken ReadToken(ILexer &lowlexer);

} // namespace highlexer
} // namespace lng