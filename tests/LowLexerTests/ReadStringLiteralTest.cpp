#include "test.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

TestCases<DefaultTestCase> ReadStringLiteralTestCases(
	{ // Correct test cases
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
	},
	{ // Incorrect test cases
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
	}
);

TEST_CASE("ReadStringLiteral()", "[lowlexer]")
{
	SECTION("can read string literal")
	{
		for (const auto &testCase : ReadStringLiteralTestCases.AllTestCases())
		{
			REQUIRE(ReadStringLiteral({ testCase.data, 0 }) == testCase.expected);
		}
	}
}