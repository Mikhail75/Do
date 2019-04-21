#pragma once

#include "Token.h"
#include "LexerTypes.h"

namespace lng
{
namespace lowlexer
{

struct ReadData
{
	std::string_view raw;
	size_t position;
};

size_t SkipSpaces(const ReadData &data);

bool InRange(const ReadData &data);
bool Match(const Predicate &predicate, const ReadData &data);

opt_char Read(const ReadData &data);
opt_char ReadIf(const Predicate &predicate, const ReadData &data);
std::string ReadWhile(const Predicate &predicate, const ReadData &data);
opt_string ReadBetween(char edge, const ReadData &data);

token::OptToken ReadSingleSign(const ReadData &data);
token::OptToken ReadNumber(const ReadData &data);
token::OptToken ReadIdentifier(const ReadData &data);
token::OptToken ReadStringLiteral(const ReadData &data);

token::OptToken ReadToken(const ReadData &data);

} // Namespace lowlexer
} // Namespace lng