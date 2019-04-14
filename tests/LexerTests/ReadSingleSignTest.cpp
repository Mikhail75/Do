#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
vector<TestCase> testCases = {
	// Correct test data
	{
		"+"sv, Token{ TT_PLUS, { 0, "+" } }
	},
	{
		"-"sv, Token{ TT_MINUS, { 0, "-" } }
	},
	{
		"*"sv, Token{ TT_ASTERISK, { 0, "*" } }
	},
	{
		"/"sv, Token{ TT_SLASH, { 0, "/" } } 
	},
	{
		"="sv, Token{ TT_EQUALS, { 0, "=" } } 
	},
	{ 
		"%"sv, Token{ TT_PERCENT, { 0, "%" } } 
	},
	{ 
		"&"sv, Token{ TT_AMPERSAND, { 0, "&" } } 
	},
	{ 
		"|"sv, Token{ TT_VERTICAL_LINE, { 0, "|" } }
	},
	{ 
		"!"sv, Token{ TT_EXLAMATION_MARK, { 0, "!" } } 
	},
	{
		"("sv, Token{ TT_LEFT_PARENTHESIS, { 0, "(" } }
	},
	{
		")"sv, Token{ TT_RIGHT_PARENTHESIS, { 0, ")" } }
	},
	{ 
		"["sv, Token{ TT_LEFT_BRACKET, { 0, "[" } }
	},
	{
		"]"sv, Token{ TT_RIGHT_BRACKET, { 0, "]" } }
	},
	{
		"{"sv, Token{ TT_LEFT_CURLY_BRACKET, { 0, "{" } } 
	},
	{ 
		"}"sv, Token{ TT_RIGHT_CURLY_BRACKET, { 0, "}" } }
	},
	{
		"<"sv, Token{ TT_LESS_THAN, { 0, "<" } } 
	},
	{
		">"sv, Token{ TT_GREATER_THAN, { 0, ">" } } 
	},
	{
		","sv, Token{ TT_COMMA, { 0, "," } }
	},
	{
		"."sv, Token{ TT_FULL_STOP, { 0, "." } } 
	},
	
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