#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
map<string_view, opt_token> testData = {
	// Correct test data
	{
		"\"\"",
		Token{ TT_STRING_LITERAL, { 0, "" } }
	},
	{
		"\"abcde\"",
		Token{ TT_STRING_LITERAL, { 0, "abcde"} }
	},
	{
		"\"12345\"",
		Token{ TT_STRING_LITERAL, { 0, "12345"} }
	},
	{
		"\'\'",
		Token{ TT_STRING_LITERAL, { 0, ""} }
	},
	{
		"\'abcde\'",
		Token{ TT_STRING_LITERAL, { 0, "abcde"} }
	},
	{
		"\'12345\'",
		Token{ TT_STRING_LITERAL, { 0, "12345"} }
	},
	// Incorrect test data
	{
		"\"\'",
		nullopt
	},
	{
		"\'\"",
		nullopt
	},
	{
		"\"abcde",
		nullopt
	},
	{
		"\'abcde",
		nullopt
	},
};
} // End namespace

TEST_CASE("Can read string literal", "[lexer]")
{
	for (const auto &data : testData)
	{
		REQUIRE(ReadStringLiteral({ data.first, 0 }) == data.second);
	}
}
