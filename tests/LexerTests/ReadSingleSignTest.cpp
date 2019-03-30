#include "test.h"

using namespace std;
using namespace lng::lexer;

TEST_CASE("Can read single sign", "[lexer]")
{
	// Correct test data
	REQUIRE(ReadSingleSign({ "+"sv, 0 }) == Token{ TT_PLUS });
	REQUIRE(ReadSingleSign({ "-"sv, 0 }) == Token{ TT_MINUS });
	REQUIRE(ReadSingleSign({ "*"sv, 0 }) == Token{ TT_ASTERISK });
	REQUIRE(ReadSingleSign({ "/"sv, 0 }) == Token{ TT_SLASH });
	REQUIRE(ReadSingleSign({ "="sv, 0 }) == Token{ TT_EQUALS });
	REQUIRE(ReadSingleSign({ "%"sv, 0 }) == Token{ TT_PERCENT });
	REQUIRE(ReadSingleSign({ "&"sv, 0 }) == Token{ TT_AMPERSAND });
	REQUIRE(ReadSingleSign({ "|"sv, 0 }) == Token{ TT_VERTICAL_LINE });
	REQUIRE(ReadSingleSign({ "!"sv, 0 }) == Token{ TT_EXLAMATION_MARK });
	REQUIRE(ReadSingleSign({ "("sv, 0 }) == Token{ TT_LEFT_PARENTHESIS });
	REQUIRE(ReadSingleSign({ ")"sv, 0 }) == Token{ TT_RIGHT_PARENTHESIS });
	REQUIRE(ReadSingleSign({ "["sv, 0 }) == Token{ TT_LEFT_BRACKET });
	REQUIRE(ReadSingleSign({ "]"sv, 0 }) == Token{ TT_RIGHT_BRACKET });
	REQUIRE(ReadSingleSign({ "{"sv, 0 }) == Token{ TT_LEFT_CURLY_BRACKET });
	REQUIRE(ReadSingleSign({ "}"sv, 0 }) == Token{ TT_RIGHT_CURLY_BRACKET });
	REQUIRE(ReadSingleSign({ "<"sv, 0 }) == Token{ TT_LESS_THAN });
	REQUIRE(ReadSingleSign({ ">"sv, 0 }) == Token{ TT_GREATER_THAN });
	REQUIRE(ReadSingleSign({ ","sv, 0 }) == Token{ TT_COMMA });
	REQUIRE(ReadSingleSign({ "."sv, 0 }) == Token{ TT_FULL_STOP });

	// Incorrect test data
	REQUIRE(ReadSingleSign({ "A"sv, 0 }) == nullopt);
	REQUIRE(ReadSingleSign({ "0"sv, 0 }) == nullopt);
	REQUIRE(ReadSingleSign({ "#"sv, 0 }) == nullopt);
}