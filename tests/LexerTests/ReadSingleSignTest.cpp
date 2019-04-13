#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
vector<TestCase> testCases = {
	// Correct test data
	{ "+"sv, Token{ TT_PLUS } },
	{ "-"sv, Token{ TT_MINUS } },
	{ "*"sv, Token{ TT_ASTERISK } },
	{ "/"sv, Token{ TT_SLASH } },
	{ "="sv, Token{ TT_EQUALS } },
	{ "%"sv, Token{ TT_PERCENT } },
	{ "&"sv, Token{ TT_AMPERSAND } },
	{ "|"sv, Token{ TT_VERTICAL_LINE } },
	{ "!"sv, Token{ TT_EXLAMATION_MARK } },
	{ "("sv, Token{ TT_LEFT_PARENTHESIS } },
	{ ")"sv, Token{ TT_RIGHT_PARENTHESIS } },
	{ "["sv, Token{ TT_LEFT_BRACKET } },
	{ "]"sv, Token{ TT_RIGHT_BRACKET } },
	{ "{"sv, Token{ TT_LEFT_CURLY_BRACKET } },
	{ "}"sv, Token{ TT_RIGHT_CURLY_BRACKET } },
	{ "<"sv, Token{ TT_LESS_THAN } },
	{ ">"sv, Token{ TT_GREATER_THAN } },
	{ ","sv, Token{ TT_COMMA } },
	{ "."sv, Token{ TT_FULL_STOP } },
	
	// Incorrect test data
	{ "A"sv, nullopt },
	{ "0"sv, nullopt },
	{ "#"sv, nullopt },
};
}

TEST_CASE("ReadSingleSign()", "[lexer]")
{
	SECTION("can read single sign")
	{
		for (const auto &testCase : testCases)
		{
			REQUIRE(ReadSingleSign({ testCase.data, 0 }) == testCase.expected);
		}
	}
}