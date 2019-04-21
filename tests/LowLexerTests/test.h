#pragma once

#include <string_view>
#include <map>

#include "catch.hpp"

#include "LowLexer.h"
#include "TokenUtils.h"

template <typename TestData, typename Expected>
struct AbstractTestCase
{
	TestData data;
	Expected expected;
};

using TestCase = AbstractTestCase<std::string_view, lng::token::OptToken>;
