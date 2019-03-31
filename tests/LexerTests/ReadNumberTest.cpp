#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
vector<TestCase> testCases = {
	// Correct test data
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
	// Incorrect test data
	{
		"&%#"sv,
		nullopt
	},
	{
		".01"sv,
		nullopt	
	},
};
}

TEST_CASE("Can read number", "[lexer]")
{
	for (const auto &testCase : testCases)
	{
		REQUIRE(ReadNumber({ testCase.data, 0 }) == testCase.expected);
	}
}