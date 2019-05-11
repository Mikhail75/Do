#include "stdafx.h"
#include "ast.h"
#include "Parser.h"
#include "ParserUtils.h"

using namespace std;

namespace lng
{
namespace parser
{

ASTNode Program(ILexer &lexer)
{
	auto program = make_shared<ASTProgram>();

	ParseNode(MainFunction, program->main_function, lexer);
	ParseNodes(FunctionDeclaration, program->function_declarations, lexer);
	
	return program;
}

ASTNode MainFunction(ILexer &lexer)
{
	return nullptr;
}

ASTNode FunctionDeclaration(ILexer &lexer)
{
	return nullptr;
}

} // namespace parser
} // namespace lng