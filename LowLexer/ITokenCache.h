#pragma once

#include "Token.h"

namespace lng
{
namespace lowlexer
{

class ITokenCache
{
public:
	virtual ~ITokenCache() = default;

	virtual void Add(size_t position, const token::OptToken &token) = 0;
	virtual void Remove(size_t position) = 0;
	virtual token::OptToken Read(size_t position) = 0;
};

} // Namespace lowlexer
} // Namespace lng