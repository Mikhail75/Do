#pragma once

#include <optional>
#include <functional>
#include "Token.h"

namespace lng
{
namespace lowlexer
{

struct ReadData;

using opt_char = std::optional<char>;
using opt_string = std::optional<std::string>;

using Predicate = std::function<bool(opt_char)>;


} // Namespace lowlexer
} // Namespace lng