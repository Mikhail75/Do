#pragma once

namespace lng
{
namespace parser
{

struct ASTProgram;
struct ASTMainFunction;
struct ASTFunctionDeclaration;

class IASTVisitor
{
public:
	virtual ~IASTVisitor() = default;

	virtual void Visit(ASTProgram &node) = 0;
	virtual void Visit(ASTMainFunction &node) = 0;
	virtual void Visit(ASTFunctionDeclaration &node) = 0;
};

} // namespace parser
} // namespace lng