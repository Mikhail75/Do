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

// Test case types
using DefaultTestCase = AbstractTestCase<std::string_view, lng::token::OptToken>;
using SkipSpacesTestCase = AbstractTestCase<std::string_view, size_t>;

template <typename TestCaseType>
struct TestCases
{
	TestCases(const std::vector<TestCaseType> &correctCases, const std::vector<TestCaseType> &incorrectCases)
		: m_correctCases(correctCases), m_incorrectCases(incorrectCases)
	{}
	
	std::vector<TestCaseType> CorrectTestCases() const
	{
		return m_correctCases;
	}

	std::vector<TestCaseType> IncorrectTestCases() const
	{
		return m_incorrectCases;
	}

	std::vector<TestCaseType> AllTestCases() const
	{
		std::vector<TestCaseType> allTestCases;

		allTestCases.insert(allTestCases.end(), m_correctCases.begin(), m_correctCases.end());
		allTestCases.insert(allTestCases.end(), m_incorrectCases.begin(), m_incorrectCases.end());

		return allTestCases;
	}

private:
	const std::vector<TestCaseType> m_correctCases;
	const std::vector<TestCaseType> m_incorrectCases;
};
