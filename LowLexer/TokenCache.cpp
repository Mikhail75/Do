#include "stdafx.h"
#include "TokenCache.h"

using namespace std;
using namespace lng::token;

namespace lng
{
namespace lowlexer
{

void CTokenCache::Add(size_t position, const OptToken &token)
{
	if (token && !m_tokens.count(position))
	{
		m_tokens[position] = token.value();
	}
}

void CTokenCache::Remove(size_t position)
{
	if (m_tokens.count(position))
	{
		m_tokens.erase(position);
	}
}

OptToken CTokenCache::Read(size_t position)
{
	if (m_tokens.count(position))
	{
		return m_tokens.at(position);
	}

	return nullopt;
}

} // Namespace lowlexer
} // Namespace lng