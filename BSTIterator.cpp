#include "BSTIterator.hpp"
#include <stdexcept>

using namespace std;

BSTIterator::BSTIterator(TreeNode* root)
{
	pushNodes(root);
}

bool BSTIterator::hasNext()
{
	return !stack.empty();
}

int BSTIterator::next()
{
	if(!hasNext())
	{
		throw "No more elements";
	}
	TreeNode top = stack.top();
	stack.pop();
	if(top.right != NULL)
	{
		pushNodes(top.right);
	}
	return top.val;
}

void BSTIterator::pushNodes(TreeNode* node)
{
	while(node != NULL)
	{
		stack.push(*node);
		node = &(*node->left);
	}
}



