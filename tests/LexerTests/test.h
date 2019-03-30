#pragma once

#include <string_view>
#include <map>

#include "catch.hpp"

#include "Lexer.h"
#include "LexerUtils.h"

template <typename TestData, typename Expected>
struct AbstractTestCase
{
	TestData data;
	Expected expected;
};

using TestCase = AbstractTestCase<std::string_view, lng::lexer::opt_token>;