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
			Token{ TT_RIGHT_BRACKET, { 5, "]" } },
			Token{ TT_IDENTIFIER, { 7, "main" } },
			Token{ TT_LEFT_CURLY_BRACKET, { 12, "{" } },
		},
		{ // Expected
			Token{ TT_FUNCTION_MAIN, { 0, "" } }
		}
	},
	{ // Test case (wrong data)
		{ // Data (token list for mock low lexer)
			Token{ TT_LESS_THAN, { 0, "<" } },
			Token{ TT_IDENTIFIER, { 1, "func" } },
			Token{ TT_GREATER_THAN, { 5, ">" } },
			Token{ TT_IDENTIFIER, { 7, "main" } },
			Token{ TT_LEFT_CURLY_BRACKET, { 12, "{" } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case (wrong data)
		{ // Data (token list for mock low lexer)
			Token{ TT_LEFT_BRACKET, { 0, "[" } },
			Token{ TT_IDENTIFIER, { 1, "func" } },
			Token{ TT_RIGHT_BRACKET, { 5, "]" } },
			Token{ TT_IDENTIFIER, { 7, "mein" } },
			Token{ TT_LEFT_CURLY_BRACKET, { 12, "{" } },
		},
		{ // Expected
			nullopt
		}
	},
};

}

TEST_CASE("ReadMainFunction()", "[highlexer]")
{
	SECTION("can read main function")
	{
		for (const auto &testCase : testCases)
		{
			lng::CMockLowLexer lexer{ testCase.data };
			REQUIRE(ReadMainFunction(lexer) == testCase.expected);
		}
	}
}