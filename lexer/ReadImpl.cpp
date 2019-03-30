#include "stdafx.h"
#include "Lexer.h"

using namespace std;

namespace lng
{
namespace lexer
{

bool InRange(const ReadData &data)
{
	return data.position < data.raw.size();
}

bool Match(const Predicate &predicate, const ReadData &data)
{
	if (InRange(data))
	{
		return predicate(Read(data));
	}
	return false;
}

opt_char Read(const ReadData &data)
{
	if (InRange(data))
	{
		return data.raw[data.position];
	}
	return nullopt;
}

opt_char ReadIf(const Predicate &predicate, const ReadData &data)
{
	if (auto value = Read(data); predicate(value))
	{
		return value;
	}
	return nullopt;
}

string ReadWhile(const Predicate &predicate, const ReadData &data)
{
	auto [raw, position] = data;
	string result = "";

	while (Match(predicate, { raw, position }))
	{
		result += Read({ raw, position++ }).value();
	}
	return result;
}

opt_string ReadBetween(char edge, const ReadData &data)
{
	if (auto first = Read(data); first == edge)
	{
		auto NotEdge = [&](opt_char value) -> bool { return value != edge; };
		auto[raw, position] = data;
		
		auto result = ReadWhile(NotEdge, { raw, ++position });

		if (auto edgeAfter = Read({ raw, position + result.size() }); edgeAfter == edge)
		{
			return result;
		}
	}
	return nullopt;
}

} // End namespace lexer
} // End namespace lng