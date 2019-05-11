#pragma once

#include "ILexer.h"
#include "IASTNode.h"

namespace lng
{
namespace parser
{

ASTNode Program(ILexer &lexer);
ASTNode MainFunction(ILexer &lexer);
ASTNode FunctionDeclaration(ILexer &lexer);

} // namespace parser
} // namespace lng