#include "test.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

TestCases<DefaultTestCase> ReadNumberTestCases(
	{ // Correct test cases
		{ 
			"1"sv,
			Token{ TT_NUMBER, { 0, "1" } }
		},
		{
			"0123456789"sv,
			Token{ TT_NUMBER, { 0, "0123456789" } }
		},
		{
			"333&333"sv,
			Token{ TT_NUMBER, { 0, "333" } }
		},
		{
		"789.012"sv,
		Token{ TT_NUMBER, { 0, "789" } }
		},
		{
			"345 678"sv,
			Token{ TT_NUMBER, { 0, "345" } }
		},
	},
	{ // Incorrect test cases
		{
			"&%#"sv,
			nullopt
		},
		{
			".01"sv,
			nullopt
		},
	}
);

TEST_CASE("ReadNumber()", "[lowlexer]")
{
	SECTION("can read number")
	{
		for (const auto &testCase : ReadNumberTestCases.AllTestCases())
		{
			REQUIRE(ReadNumber({ testCase.data, 0 }) == testCase.expected);
		}
	}
}