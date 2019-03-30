#pragma once

#include "Token.h"

namespace lng
{
namespace lexer
{

struct ReadData
{
	string_view raw;
	size_t position;
};

size_t SkipSpaces(const ReadData &data);

bool InRange(const ReadData &data);
bool Match(const Predicate &predicate, const ReadData &data);

opt_char Read(const ReadData &data);
opt_char ReadIf(const Predicate &predicate, const ReadData &data);
string ReadWhile(const Predicate &predicate, const ReadData &data);
opt_string ReadBetween(char edge, const ReadData &data);

opt_token ReadSingleSign(const ReadData &data);
opt_token ReadStringLiteral(const ReadData &data);
opt_token ReadNumber(const ReadData &data);

opt_token ReadToken(const ReadData &data);

} // End namespace lexer
} // End namespace lng