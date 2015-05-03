#pragma once
#ifndef __TREENODE__
#define __TREENODE__

#include <stdio.h>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

#endif