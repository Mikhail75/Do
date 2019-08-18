#pragma once

#include "ITokenCache.h"

namespace lng
{
namespace lowlexer
{

class CTokenCache : public ITokenCache
{
public:
	void Add(size_t position, const token::OptToken &token) override;
	void Remove(size_t position) override;
	token::OptToken Read(size_t position) override;

private:
	std::map<size_t, token::Token> m_tokens;
};

} // Namespace lowlexer
} // Namespace lng