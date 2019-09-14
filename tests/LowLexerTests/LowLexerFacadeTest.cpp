#include "test.h"
#include "LowLexerFacade.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

namespace
{
	using LexerFacadeTestCase = AbstractTestCase<std::string_view, vector<OptToken>>;
	
	TestCases<LexerFacadeTestCase> lexerFacadeTestCases(
		{ // Correct test cases
			{ // Test case #1
				" \n + 'literal' identifier 12345 ",
				{
					Token{TT_PLUS, {3, "+"}},
					Token{TT_STRING_LITERAL, {5, "literal"}},
					Token{TT_IDENTIFIER, {15, "identifier"}},
					Token{TT_NUMBER, {26, "12345"}},
					nullopt,
				}
			},
			{ // Test case #2
				"26.945",
				{
					Token{TT_NUMBER, {0, "26"}},
					Token{TT_FULL_STOP, {2, "."}},
					Token{TT_NUMBER, {3, "945"}},
				}
			},
			{ // Test case #3
				"[func] main {",
				{
					Token{TT_LEFT_BRACKET, {0, "["}},
					Token{TT_IDENTIFIER, {1, "func"}},
					Token{TT_RIGHT_BRACKET, {5, "]"}},
					Token{TT_IDENTIFIER, {7, "main"}},
					Token{TT_LEFT_CURLY_BRACKET, {12, "{"}},
				}
			},
			{ // Test case #4
				"[func",
				{
					Token{TT_LEFT_BRACKET, {0, "["}},
					Token{TT_IDENTIFIER, {1, "func"}},
				}
			}
		},
		{ // Incorrect test cases
		}
	);
}

TEST_CASE("CLowLexerFacade", "[lowlexer]")
{
	SECTION("can read tokens")
	{
		for (const auto &testCase : lexerFacadeTestCases.CorrectTestCases())
		{
			CLowLexerFacade lexer(testCase.data);

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(lexer.Next() == expected);
			}
		}
	}

	SECTION("can peek one token")
	{
		for (const auto &testCase : lexerFacadeTestCases.CorrectTestCases())
		{
			CLowLexerFacade lexer(testCase.data);

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(lexer.Peek() == expected);
				REQUIRE(lexer.Next() == expected);
			}
		}
	}

	SECTION("should use cache when peek one token")
	{
		for (const auto &testCase : lexerFacadeTestCases.CorrectTestCases())
		{
			auto cache = make_shared<CTokenCache>();
			CLowLexerFacade lexer(testCase.data, 0, cache);

			size_t position = 0;

			for (const auto &expected : testCase.expected)
			{
				lexer.Peek();
				REQUIRE(cache->Read(position) == expected);

				lexer.Next();
				REQUIRE(cache->Read(position) == nullopt);

				position = SkipSpaces({ testCase.data, position });
				if (expected)
				{
					position += GetTokenLength(expected.value());
				}
			}
		}
	}

	SECTION("can peek several tokens")
	{
		for (const auto &testCase : lexerFacadeTestCases.CorrectTestCases())
		{
			CLowLexerFacade lexer(testCase.data);
			auto peekedTokens = lexer.Peek(testCase.expected.size());

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
				REQUIRE(lexer.Next() == expected);
			}
		}
	}

	SECTION("should use cache when peek several tokens")
	{
		for (const auto &testCase : lexerFacadeTestCases.CorrectTestCases())
		{
			auto cache = make_shared<CTokenCache>();
			CLowLexerFacade lexer(testCase.data, 0, cache);

			auto peekedTokens = lexer.Peek(testCase.expected.size());
			size_t position = 0;

			for (const auto &expected : testCase.expected)
			{
				REQUIRE(cache->Read(position) == expected);

				position = SkipSpaces({ testCase.data, position });
				if (expected)
				{
					position += GetTokenLength(expected.value());
				}
			}
		}
	}
}