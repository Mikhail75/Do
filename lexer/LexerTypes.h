#pragma once

#include <optional>
#include <functional>

namespace lng
{
namespace lexer
{

struct Token;
struct ReadData;

using string = std::string;
using string_view = std::string_view;

using opt_char = std::optional<char>;
using opt_string = std::optional<string>;

using opt_token = std::optional<Token>;
using Predicate = std::function<bool(opt_char)>;

using ReadTokenFunc = std::function<opt_token(const ReadData&)>;

} // End namespace lexer
} // End namespace lng