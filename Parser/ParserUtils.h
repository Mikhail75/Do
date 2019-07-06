#pragma once

#include <functional>
#include "ILexer.h"
#include "IASTNode.h"
#include "MatchResult.h"

namespace lng
{
namespace parser
{
using ParseNodeHandler = const std::function<ASTNode(ILexer&)>;

void ParseNode(ParseNodeHandler &handler, ASTNode &node, ILexer &lexer);
void ParseNodes(ParseNodeHandler &handler, ASTNodeList &nodes, ILexer &lexer);

MatchResult MatchTokensByTypes(const std::initializer_list<token::TokenType> &tokenTypes, ILexer &lexer);
void MatchTokensByTypesWithExcept(const std::initializer_list<token::TokenType> &tokenTypes, ILexer &lexer);

} // namespace parser
} // namespace lng