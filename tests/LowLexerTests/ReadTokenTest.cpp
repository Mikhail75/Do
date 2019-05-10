#include "test.h"
#include <functional>

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

extern TestCases<DefaultTestCase> ReadSingleSignTestCases;
extern TestCases<DefaultTestCase> ReadStringLiteralTestCases;
extern TestCases<DefaultTestCase> ReadNumberTestCases;
extern TestCases<DefaultTestCase> ReadIdentifierTestCases;

vector<DefaultTestCase> ReadTokenTestSkipSpacesTestCases {
	{
		" a"sv, Token{ TT_IDENTIFIER, { 1, "a" }}
	},
	{
		"\t1"sv, Token{ TT_NUMBER, { 1, "1" }}
	},
	{
		"\n\"a\""sv, Token{ TT_STRING_LITERAL, { 1, "a" }}
	},
	{
		"\r+"sv, Token{ TT_PLUS, { 1, "+" }}
	},
	{
		"   a"sv, Token{ TT_IDENTIFIER, { 3, "a" }}
	},
	{
		"\t\t\t1"sv, Token{ TT_NUMBER, { 3, "1" }}
	},
	{
		"\n\n\n\"a\""sv, Token{ TT_STRING_LITERAL, { 3, "a" }}
	},
	{
		"\r\r\r*"sv, Token{ TT_ASTERISK, { 3, "*" }}
	},
	{
		" \t \n \r a"sv, Token{ TT_IDENTIFIER, { 7, "a" }}
	},
};

vector<DefaultTestCase> ReadTokenTestRecognizeErrorTestCases {
	{
		"Ë‰ÂÌÚËÙËÍ‡ÚÓ"sv, Token{ TT_ERROR}
	},
	{
		"Ødentifier"sv, Token{ TT_ERROR}
	},
};

vector<AbstractTestCase<pair<string_view, size_t>, OptToken>> ReadTokenTestEndOfDataTestCases {
	{
		{/*raw data*/ ""sv, /*position*/ 0}, /*expected*/ nullopt
	},
	{
		{/*raw data*/ " "sv, /*position*/ 0}, /*expected*/ nullopt
	},
	{
		{/*raw data*/ "\t"sv, /*position*/ 0}, /*expected*/ nullopt
	},
	{
		{/*raw data*/ "\n"sv, /*position*/ 0}, /*expected*/ nullopt
	},
	{
		{/*raw data*/ "\r"sv, /*position*/ 0}, /*expected*/ nullopt
	},
	{
		{/*raw data*/ "abc"sv, /*position*/ 3}, /*expected*/ nullopt
	},
};

namespace
{

template <typename TestCaseType>
void RunTestCases(const std::vector<TestCaseType> &testCases)
{
	for (const auto &testCase : testCases)
	{
		REQUIRE(ReadToken({ testCase.data, 0 }) == testCase.expected);
	}
}

} // namespace

TEST_CASE("ReadTokenTest()", "[lowlexer]")
{
	SECTION("can read single sign")
	{
		RunTestCases(ReadSingleSignTestCases.CorrectTestCases());
	}
	
	SECTION("can read string literal")
	{
		RunTestCases(ReadStringLiteralTestCases.CorrectTestCases());
	}
	
	SECTION("can read number")
	{
		RunTestCases(ReadNumberTestCases.CorrectTestCases());
	}

	SECTION("can read identifier")
	{
		RunTestCases(ReadIdentifierTestCases.CorrectTestCases());
	}

	SECTION("can skip spaces")
	{
		RunTestCases(ReadTokenTestSkipSpacesTestCases);
	}

	SECTION("can recognize errors")
	{
		RunTestCases(ReadTokenTestRecognizeErrorTestCases);
	}

	SECTION("can recognize end of data")
	{
		for (const auto &testCase : ReadTokenTestEndOfDataTestCases)
		{
			string_view rawData = testCase.data.first;
			size_t position = testCase.data.second;

			REQUIRE(ReadToken({ rawData,  position }) == testCase.expected);
		}
	}
}