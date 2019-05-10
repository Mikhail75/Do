#include "test.h"
#include "LowLexerFacade.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

namespace
{
	using LexerFacadeTestCase = AbstractTestCase<std::string_view, vector<OptToken>>;
	
	LexerFacadeTestCase testCase = {
			" \n + 'literal' identifier 12345 ",
			{
				Token{TT_PLUS, {3, "+"}},
				Token{TT_STRING_LITERAL, {5, "literal"}},
				Token{TT_IDENTIFIER, {15, "identifier"}},
				Token{TT_NUMBER, {26, "12345"}},
				nullopt,
			}
	};
}

TEST_CASE("LowLexerFacade", "[lowlexer]")
{
	SECTION("can read tokens")
	{
		LowLexerFacade lexer(testCase.data);

		for (const auto &expected : testCase.expected)
		{
			REQUIRE(lexer.Next() == expected);
		}
	}

	SECTION("can peek one token")
	{
		LowLexerFacade lexer(testCase.data);

		REQUIRE(lexer.Peek() == testCase.expected[0]);
		REQUIRE(lexer.Next() == testCase.expected[0]);
	}

	SECTION("can peek several tokens")
	{
		LowLexerFacade lexer(testCase.data);
		auto peekedTokens = lexer.Peek(4).value();

		for (size_t i = 0; i < peekedTokens.size(); ++i)
		{
			REQUIRE(peekedTokens[i] == testCase.expected[i]);
		}

		for (const auto &expected : testCase.expected)
		{
			REQUIRE(lexer.Next() == expected);
		}
	}
}