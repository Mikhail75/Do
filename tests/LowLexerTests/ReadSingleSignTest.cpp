#include "test.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

TestCases<DefaultTestCase> ReadSingleSignTestCases(
	{ // Correct test cases
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
	},
	{ // Incorrect test cases
		{ "A"sv, nullopt },
		{ "0"sv, nullopt },
		{ "#"sv, nullopt },
	}
);

TEST_CASE("ReadSingleSign()", "[lowlexer]")
{
	SECTION("can read single sign")
	{
		for (const auto &testCase : ReadSingleSignTestCases.AllTestCases())
		{
			REQUIRE(ReadSingleSign({ testCase.data, 0 }) == testCase.expected);
		}
	}
}