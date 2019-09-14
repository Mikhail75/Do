#pragma once

#include "ILexer.h"
#include "LowLexer.h"
#include "TokenCache.h"

namespace lng
{
namespace lowlexer
{

class CLowLexerFacade : public ILexer
{

public:
	CLowLexerFacade(std::string_view raw, size_t position, const std::shared_ptr<ITokenCache> &cache)
		: m_raw(raw), m_position(position), m_cache(cache)
	{}

	CLowLexerFacade(std::string_view raw, size_t position = 0)
		: m_raw(raw), m_position(position), m_cache(std::make_shared<CTokenCache>())
	{}

	token::OptToken Next() override;
	token::OptToken Peek() override;
	token::TokenList Peek(size_t numberOfTokens) override;

private:
	std::string_view m_raw;
	size_t m_position;
	const std::shared_ptr<ITokenCache> m_cache;

	token::OptToken ReadTokenImpl(size_t position);
	size_t PositionAfterToken(const token::OptToken &optToken) const;
};

} // Namespace lowlexer
} // Namespace lng