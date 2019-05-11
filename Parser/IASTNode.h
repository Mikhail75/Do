#pragma once

#include <memory>
#include "IASTVisitor.h"

namespace lng
{
namespace parser
{

struct IASTNode
{
	virtual ~IASTNode() = default;
	virtual void Accept(IASTVisitor &visitor) = 0;
};

using ASTNode = std::shared_ptr<IASTNode>;
using ASTNodeList = std::vector<ASTNode>;

} // namespace parser
} // namespace lng