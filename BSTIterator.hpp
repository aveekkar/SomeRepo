#pragma once
#ifndef	__BSTITERATOR__

#define __BSTITERATOR__

#include "TreeNode.h"
#include <stdio.h>
#include <stack>

class BSTIterator
{
public:
	BSTIterator(TreeNode* root);
	bool hasNext();
	int next();

private:
	std::stack<TreeNode> stack;
	void pushNodes(TreeNode* node);
};

#endif __BSTITERATOR__

