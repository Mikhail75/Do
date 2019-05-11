#pragma once

#include "IASTNode.h"
#include <vector>

namespace lng
{
namespace parser
{

struct ASTProgram : IASTNode
{
	ASTNode main_function;
	ASTNodeList function_declarations;

	void Accept(IASTVisitor &v) override { v.Visit(*this); }
};

struct ASTMainFunction : IASTNode
{
	ASTNodeList statements;
	
	void Accept(IASTVisitor &v) override { v.Visit(*this); }
};

struct ASTFunctionDeclaration : IASTNode
{
	void Accept(IASTVisitor &v) override { v.Visit(*this); }
};

} // namespace parser
} // namespace lng