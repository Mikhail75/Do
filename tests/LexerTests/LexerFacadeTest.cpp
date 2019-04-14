#include "test.h"
#include "LexerFacade.h"

using namespace std;
using namespace lng::lexer;

namespace
{
	using LexerFacadeTestCase = AbstractTestCase<std::string_view, vector<opt_token>>;
}

TEST_CASE("LexerFacade", "[lexer]")
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

		LexerFacade lexer(testCase.data);

		for (const auto &expected : testCase.expected)
		{
			REQUIRE(lexer.Next() == expected);
		}
	}
}