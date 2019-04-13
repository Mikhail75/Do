#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
vector<TestCase> testCases = {
	// Correct test data
	{
		"\"\""sv,
		Token{ TT_STRING_LITERAL, { 0, "" } }
	},
	{
		"\"abcde\""sv,
		Token{ TT_STRING_LITERAL, { 0, "abcde"} }
	},
	{
		"\"12345\""sv,
		Token{ TT_STRING_LITERAL, { 0, "12345"} }
	},
	{
		"\'\'"sv,
		Token{ TT_STRING_LITERAL, { 0, ""} }
	},
	{
		"\'abcde\'"sv,
		Token{ TT_STRING_LITERAL, { 0, "abcde"} }
	},
	{
		"\'12345\'"sv,
		Token{ TT_STRING_LITERAL, { 0, "12345"} }
	},
	// Incorrect test data
	{
		"\"\'"sv,
		nullopt
	},
	{
		"\'\""sv,
		nullopt
	},
	{
		"\"abcde"sv,
		nullopt
	},
	{
		"\'abcde"sv,
		nullopt
	},
};
} // End namespace

TEST_CASE("ReadStringLiteral()", "[lexer]")
{
	SECTION("can read string literal")
	{
		for (const auto &testCase : testCases)
		{
			REQUIRE(ReadStringLiteral({ testCase.data, 0 }) == testCase.expected);
		}
	}
}