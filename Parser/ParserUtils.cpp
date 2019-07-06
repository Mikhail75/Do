#include "stdafx.h"
#include "ParserUtils.h"
#include "MatchException.h"

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

MatchResult MatchTokensByTypes(const initializer_list<token::TokenType> &tokenTypes, ILexer &lexer)
{
	auto requiredTokenCount = tokenTypes.size();
	auto tokens = lexer.Peek(requiredTokenCount);

	for (size_t i = 0; i < requiredTokenCount; ++i)
	{
		auto requiredTokenType = *(tokenTypes.begin() + i);
		auto currentTokenType = i < tokens.size() ? tokens[i].type : token::TT_END;

		if (requiredTokenType != currentTokenType)
		{
			auto position = i < tokens.size() ? tokens[i].data.position : lexer.NextPosition();
			return { MatchError(position, requiredTokenType, currentTokenType) };
		}
	}

	return {};
}

void MatchTokensByTypesWithExcept(const std::initializer_list<token::TokenType> &tokenTypes, ILexer &lexer)
{
	if (auto matchResult = MatchTokensByTypes(tokenTypes, lexer); !matchResult)
	{
		throw MatchException(matchResult.GetMatchError().value());
	}
}

} // namespace parser
} // namespace lng