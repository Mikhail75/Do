#include "test.h"
#include "LowLexerFacade.h"
#include "HighLexerFacade.h"

using namespace std;
using namespace lng::token;
using namespace lng::highlexer;
using namespace lng::lowlexer;

namespace
{
using LexerFacadeTestCase = AbstractTestCase<std::string_view, vector<OptToken>>;

vector<LexerFacadeTestCase> testCases = {
	{ // Test case #1
		"26.945",
		{ // Expected
			Token{TT_FLOAT_NUMBER, {0, "26.945"}},
			nullopt,
		}
	},
	{ // Test case #2
		"[func] main { }",
		{ // Expected
			Token{TT_FUNCTION_MAIN, {0}},
			Token{TT_RIGHT_CURLY_BRACKET, {14, "}"}},
		}
	},
	{ // Test case #3
		"[func",
		{ // Expected
			Token{TT_FUNCTION, {0}},
		}
	},
};

} // namespace

TEST_CASE("CHighLexerFacade", "[highlexer]")
{
	SECTION("can read tokens")
	{
		for (const auto &testCase : testCases)
		{
			CLowLexerFacade lowlexer{ testCase.data };
			CHighLexerFacade highlexer{ lowlexer };

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(highlexer.Next() == expected);
			}
		}
	}

	SECTION("can peek one token")
	{
		for (const auto &testCase : testCases)
		{
			CLowLexerFacade lowlexer{ testCase.data };
			CHighLexerFacade highlexer{ lowlexer };

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(highlexer.Peek() == expected);
				REQUIRE(highlexer.Next() == expected);
			}
		}
	}

	SECTION("can peek several tokens")
	{
		for (const auto &testCase : testCases)
		{
			CLowLexerFacade lowlexer{ testCase.data };
			CHighLexerFacade highlexer{ lowlexer };

			auto peekedTokens = highlexer.Peek(testCase.expected.size());

			size_t expectedPeekedTokensCount = 0;
			for (const auto &expected : testCase.expected)
			{
				if (expected != nullopt)
				{
					++expectedPeekedTokensCount;
				}
			}
			REQUIRE(peekedTokens.size() == expectedPeekedTokensCount);

			for (size_t i = 0; i < peekedTokens.size(); ++i)
			{
				REQUIRE(peekedTokens[i] == testCase.expected[i]);
			}

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(highlexer.Next() == expected);
			}
		}
	}
}