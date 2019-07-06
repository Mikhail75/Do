#pragma once

#include <string_view>
#include <map>

#include "catch.hpp"

#include "HighLexer.h"
#include "TokenUtils.h"
#include "MockLowLexer.h"

template <typename TestData, typename Expected>
struct AbstractTestCase
{
	TestData data;
	Expected expected;
};

using TestCase = AbstractTestCase<lng::token::TokenList, lng::token::OptToken>;