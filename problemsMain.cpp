#include <stdio.h>
#include <vector>

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

vector<vector<int> > pathSum(TreeNode* root, int sum);
void pathSumRecurse(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& running);
int sumUpVector(vector<int>& input);

int main(int argc, char **argv)
{
	int sum = 22;
	TreeNode root(5);
	TreeNode left(4);
	TreeNode right(8);
	root.left = &left;
	root.right = &right;
	TreeNode leftLeft(11);
	TreeNode rightLeft(13);
	TreeNode rightRight(4);
	left.left = &leftLeft;
	right.left = &rightLeft;
	right.right = &rightRight;
	TreeNode leafOne(7);
	TreeNode leafTwo(2);
	TreeNode leafThree(5);
	TreeNode leafFour(1);
	leftLeft.left = &leafOne;
	leftLeft.right = &leafTwo;
	rightRight.left = &leafThree;
	rightRight.right = &leafFour;
	pathSum(&root, sum);
	getchar();
	return 0;
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
	vector<vector<int> > result;
	vector<int> runningResult;
	pathSumRecurse(root, sum, result, runningResult);
	return result;
}

void pathSumRecurse(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& running)
{
	if(root == NULL)
	{
		return;
	}
	if(root->left == NULL && root->right == NULL)
	{
		int runningSum = sumUpVector(running) + root->val;
		if(runningSum == sum)
		{
			vector<int> foundPath;
			for(int i = 0; i < running.size(); ++i)
			{
				foundPath.push_back(running[i]);
			}
			foundPath.push_back(root->val);
			result.push_back(foundPath);
		}
	}
	else
	{
		running.push_back(root->val);
		if(root->left != NULL)
		{
			 pathSumRecurse(root->left, sum, result, running);
		}
		if(root->right != NULL)
		{
			pathSumRecurse(root->right, sum, result, running);
		}
		running.pop_back();
	}
}

int sumUpVector(vector<int>& input)
{
	int sum = 0;
	for(vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
	{
		sum += (*i);
	}
	return sum;
}