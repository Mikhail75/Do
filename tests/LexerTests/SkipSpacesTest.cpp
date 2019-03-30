#include "test.h"

using namespace std;
using namespace lng::lexer;

namespace
{
using SkipSpacesTestCase = AbstractTestCase<std::string_view, size_t>;
vector<SkipSpacesTestCase> testCases {
	{" a"sv, 1},
	{"  a"sv, 2},
	{"\ta"sv, 1},
	{"\t\ta"sv, 2},
	{"\na"sv, 1},
	{"\n\na"sv, 2},
	{"\ra"sv, 1},
	{"\r\ra"sv, 2},
	{"\t\na"sv, 2},
	{" \t\na"sv, 3},
	{"a"sv, 0},
};
} // End namespace

TEST_CASE("Can skip spaces", "[lexer]")
{
	for (const auto &testCase : testCases)
	{
		REQUIRE(SkipSpaces({ testCase.data, 0 }) == testCase.expected);
	}
}