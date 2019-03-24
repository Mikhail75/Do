#include "test.h"

using namespace std;
using namespace lng::lexer;

TEST_CASE("Can read single sign", "[lexer]")
{
	// Correct test data
	REQUIRE(ReadSingleSign("+"sv, 0) == LexResult{ Token{ TT_PLUS }, 1 });
	REQUIRE(ReadSingleSign("-"sv, 0) == LexResult{ Token{ TT_MINUS }, 1 });
	REQUIRE(ReadSingleSign("*"sv, 0) == LexResult{ Token{ TT_ASTERISK }, 1 });
	REQUIRE(ReadSingleSign("/"sv, 0) == LexResult{ Token{ TT_SLASH }, 1 });
	REQUIRE(ReadSingleSign("="sv, 0) == LexResult{ Token{ TT_EQUALS }, 1 });
	REQUIRE(ReadSingleSign("%"sv, 0) == LexResult{ Token{ TT_PERCENT }, 1 });
	REQUIRE(ReadSingleSign("&"sv, 0) == LexResult{ Token{ TT_AMPERSAND }, 1 });
	REQUIRE(ReadSingleSign("|"sv, 0) == LexResult{ Token{ TT_VERTICAL_LINE }, 1 });
	REQUIRE(ReadSingleSign("!"sv, 0) == LexResult{ Token{ TT_EXLAMATION_MARK }, 1 });
	REQUIRE(ReadSingleSign("("sv, 0) == LexResult{ Token{ TT_LEFT_PARENTHESIS }, 1 });
	REQUIRE(ReadSingleSign(")"sv, 0) == LexResult{ Token{ TT_RIGHT_PARENTHESIS }, 1 });
	REQUIRE(ReadSingleSign("["sv, 0) == LexResult{ Token{ TT_LEFT_BRACKET }, 1 });
	REQUIRE(ReadSingleSign("]"sv, 0) == LexResult{ Token{ TT_RIGHT_BRACKET }, 1 });
	REQUIRE(ReadSingleSign("{"sv, 0) == LexResult{ Token{ TT_LEFT_CURLY_BRACKET }, 1 });
	REQUIRE(ReadSingleSign("}"sv, 0) == LexResult{ Token{ TT_RIGHT_CURLY_BRACKET }, 1 });
	REQUIRE(ReadSingleSign("<"sv, 0) == LexResult{ Token{ TT_LESS_THAN }, 1 });
	REQUIRE(ReadSingleSign(">"sv, 0) == LexResult{ Token{ TT_GREATER_THAN }, 1 });
	REQUIRE(ReadSingleSign(","sv, 0) == LexResult{ Token{ TT_COMMA }, 1 });
	REQUIRE(ReadSingleSign("."sv, 0) == LexResult{ Token{ TT_FULL_STOP }, 1 });

	// Incorrect test data
	REQUIRE(ReadSingleSign("A"sv, 0) == LexResult{ nullopt, 0 });
	REQUIRE(ReadSingleSign("0"sv, 0) == LexResult{ nullopt, 0 });
	REQUIRE(ReadSingleSign("#"sv, 0) == LexResult{ nullopt, 0 });
}