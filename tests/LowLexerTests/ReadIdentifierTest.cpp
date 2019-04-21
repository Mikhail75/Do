#include "test.h"

using namespace std;
using namespace lng::lowlexer;
using namespace lng::token;

namespace
{
	vector<TestCase> testCases = {
		{
			"a"sv,
			Token{ TT_IDENTIFIER, { 0, "a" } }
		},
		{
			"_a"sv,
			Token{ TT_IDENTIFIER, { 0, "_a" } }
		},
		{
			"a_"sv,
			Token{ TT_IDENTIFIER, { 0, "a_" } }
		},
		{
			"a1"sv,
			Token{ TT_IDENTIFIER, { 0, "a1" } }
		},
		{
			"_a1"sv,
			Token{ TT_IDENTIFIER, { 0, "_a1" } }
		},
		{
			"a1_"sv,
			Token{ TT_IDENTIFIER, { 0, "a1_" } }
		},
		{
			"_"sv,
			Token{ TT_IDENTIFIER, { 0, "_" } }
		},
		{
			"abcde"sv,
			Token{ TT_IDENTIFIER, { 0, "abcde" } }
		},
	};
}

TEST_CASE("ReadIdentifier()", "[lowlexer]")
{
	SECTION("can read identifier")
	{
		for (const auto &testCase : testCases)
		{
			REQUIRE(ReadIdentifier({ testCase.data, 0 }) == testCase.expected);
		}
	}

	SECTION("must support the entire character set")
	{
		string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_01234567890";
		string prefix = "a"; // Required for testing digits (id cannot begin with a digit)

		for (char value : charset)
		{
			OptToken expected = make_optional(Token{ TT_IDENTIFIER, {0, prefix + value } });
			REQUIRE(ReadIdentifier({ prefix + &value, 0 }) == expected);
		}
	}

	SECTION("cannot read identifiers that begin with a digit")
	{
		string digits = "01234567890";

		for (char value : digits)
		{
			REQUIRE(ReadIdentifier({ &value, 0 }) == nullopt);
		}
	}

	SECTION("cannot read identifiers with non-set characters")
	{
		string nonSetChars = "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~Ђ‘’“”•–—™љ›њќћџЎў¤Ґ¦§Ё©Є«¬®Ї°±Ііґµ¶·ё№є»јЅѕїАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";

		for (char value : nonSetChars)
		{
			REQUIRE(ReadIdentifier({ &value, 0 }) == nullopt);
		}
	}
}