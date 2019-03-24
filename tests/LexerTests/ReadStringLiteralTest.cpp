#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
map<string_view, LexResult> testData = {
	// Correct test data
	{
		"\"\"",
		LexResult {Token{TT_STRING_LITERAL, ""}, 2}
	},
	{
		"\"abcde\"",
		LexResult {Token{TT_STRING_LITERAL, "abcde"}, 7}
	},
	{
		"\"12345\"",
		LexResult {Token{TT_STRING_LITERAL, "12345"}, 7}
	},
	{
		"\'\'",
		LexResult {Token{TT_STRING_LITERAL, ""}, 2}
	},
	{
		"\'abcde\'",
		LexResult {Token{TT_STRING_LITERAL, "abcde"}, 7}
	},
	{
		"\'12345\'",
		LexResult {Token{TT_STRING_LITERAL, "12345"}, 7}
	},
	// Incorrect test data
	{
		"\"\'",
		LexResult {nullopt, 0}
	},
	{
		"\'\"",
		LexResult {nullopt, 0}
	},
};

} // End namespace

TEST_CASE("Can read string literal", "[lexer]")
{
	for (const auto &data : testData)
	{
		REQUIRE(ReadStringLiteral(data.first, 0) == data.second);
	}
}
