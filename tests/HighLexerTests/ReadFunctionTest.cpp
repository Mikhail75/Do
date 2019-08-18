#include "test.h"

using namespace std;
using namespace lng::token;
using namespace lng::highlexer;

namespace
{

vector<TestCase> testCases = {
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_LEFT_BRACKET, { 0, "[" } },
			Token{ TT_IDENTIFIER, { 1, "func" } },
		},
		{ // Expected
			Token{ TT_FUNCTION, { 0, "" } }
		}
	},
	{ // Test case (wrong data)
		{ // Data (token list for mock low lexer)
			Token{ TT_LESS_THAN, { 0, "<" } },
			Token{ TT_IDENTIFIER, { 1, "func" } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case (wrong data)
		{ // Data (token list for mock low lexer)
			Token{ TT_LEFT_BRACKET, { 0, "[" } },
			Token{ TT_IDENTIFIER, { 1, "funk" } },
		},
		{ // Expected
			nullopt
		}
	},
};

}

TEST_CASE("ReadFunction()", "[highlexer]")
{
	SECTION("can read function")
	{
		for (const auto &testCase : testCases)
		{
			lng::CMockLowLexer lexer{ testCase.data };
			REQUIRE(ReadFunction(lexer) == testCase.expected);
		}
	}
}