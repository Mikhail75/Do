#include "test.h"
#include "LowLexerFacade.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

namespace
{
	using LexerFacadeTestCase = AbstractTestCase<std::string_view, vector<OptToken>>;
}

TEST_CASE("LowLexerFacade", "[lowlexer]")
{
	SECTION("can read tokens")
	{
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

		LowLexerFacade lexer(testCase.data);

		for (const auto &expected : testCase.expected)
		{
			REQUIRE(lexer.Next() == expected);
		}
	}
}