#include "test.h"

using namespace std;
using namespace lng::token;
using namespace lng::highlexer;

namespace
{

vector<TestCase> testCases = {
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 1, "." } },
			Token{ TT_NUMBER, { 2, "1" } },
		},
		{ // Expected
			Token{ TT_FLOAT_NUMBER, { 0, "1.1" } }
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "0" } },
			Token{ TT_FULL_STOP, { 1, "." } },
			Token{ TT_NUMBER, { 2, "1" } },
		},
		{ // Expected
			Token{ TT_FLOAT_NUMBER, { 0, "0.1" } }
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 1, "." } },
			Token{ TT_NUMBER, { 2, "0" } },
		},
		{ // Expected
			Token{ TT_FLOAT_NUMBER, { 0, "1.0" } }
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "13570" } },
			Token{ TT_FULL_STOP, { 5, "." } },
			Token{ TT_NUMBER, { 6, "2469" } },
		},
		{ // Expected
			Token{ TT_FLOAT_NUMBER, { 0, "13570.2469" } }
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 1, "." } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "." } },
			Token{ TT_FULL_STOP, { 1, "1" } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 2, "." } }, // Emulate space before TT_FULL_STOP
			Token{ TT_NUMBER, { 3, "1" } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 1, "." } }, 
			Token{ TT_NUMBER, { 3, "1" } }, // Emulate space before TT_NUMBER
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_FULL_STOP, { 2, "." } }, // Emulate space before TT_NUMBER
			Token{ TT_NUMBER, { 5, "1" } }, // Emulate space before TT_NUMBER
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_NUMBER, { 0, "1" } },
			Token{ TT_COMMA, { 1, "," } },
			Token{ TT_NUMBER, { 2, "1" } },
		},
		{ // Expected
			nullopt
		}
	},
	{ // Test case
		{ // Data (token list for mock low lexer)
			Token{ TT_IDENTIFIER, { 0, "abc" } },
			Token{ TT_FULL_STOP, { 1, "." } },
			Token{ TT_NUMBER, { 2, "1" } },
		},
		{ // Expected
			nullopt
		}
	},
};
}

TEST_CASE("ReadFloatNumber()", "[highlexer]")
{
	SECTION("can read float number")
	{
		for (const auto &testCase : testCases)
		{
			lng::CMockLowLexer lexer{ testCase.data };
			REQUIRE(ReadFloatNumber(lexer) == testCase.expected);
		}
	}
}