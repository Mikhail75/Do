#include "stdafx.h"
#include "ParserUtils.h"

using namespace std;

namespace lng
{
namespace parser
{

void ParseNode(ParseNodeHandler &handler, ASTNode &node, ILexer &lexer)
{
	node = handler(lexer);
}

void ParseNodes(ParseNodeHandler &handler, ASTNodeList &nodes, ILexer &lexer)
{
	auto ParseNodeImpl = [&]() -> bool {
		if (auto value = handler(lexer); value.get() != nullptr)
		{
			nodes.push_back(value);
			return true;
		}
		return false;
	};
	while (ParseNodeImpl()) {}
}

} // namespace parser
} // namespace lng