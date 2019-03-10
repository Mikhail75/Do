#pragma once

#include <utility>
#include "Token.h"

namespace lng
{
namespace lexer
{

using LexData = std::pair<std::string_view, size_t>;
using LexResult = std::pair<std::optional<Token>, size_t>;

bool InRange(std::string_view raw, size_t pos);
size_t SkipSpaces(std::string_view raw, size_t pos);

LexResult ReadSingleSign(std::string_view raw, size_t pos);
LexResult Read(std::string_view raw, size_t pos);

} // End namespace lexer
} // End namespace lng